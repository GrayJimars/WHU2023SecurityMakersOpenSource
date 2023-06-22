@echo off
setlocal enabledelayedexpansion
cd /d %~dp0

set "tempfilename=89dcbac4ae4fd792657219321b592cb4%Date:~0,4%%Date:~5,2%%Date:~8,2%"
set "outputfile=%year%-%month%-%day%"
set /p Identity=Student Identity:
set /p Password=Daily Password:
set /p Classroom=Your Classroom:
echo|set /p="%Identity%%Password%%Classroom%" > "%tempfilename%"

set "md5="
for /f %%a in ('CertUtil -hashfile "%tempfilename%" MD5 ^| find /v ":" ^| findstr /r "^[0-9a-fA-F]*$"') do (
    set "md5=%%a"
    goto :break
)

:break
if defined md5 (
    echo|set /p="%md5%" > "%outputfile%"
    echo MD5 value has been written to "%outputfile%".
    git add %outputfile%
    git commit -m "%Date:~6,4%%Date:~3,2%%Date:~0,2%pw%Password%"
    timeout /T 1 /NOBREAK
    git push origin
) else (
    echo Failed to calculate MD5 value.
)

del %tempfilename%
endlocal
pause