@echo off
setlocal enabledelayedexpansion
cd /d %~dp0

set "tempfilename=89dcbac4ae4fd792657219321b592cb4%Date:~6,4%%Date:~3,2%%Date:~0,2%"
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
    %git命令从这里开始%
    git add %outputfile%
    git commit -m "%Date:~6,4%%Date:~3,2%%Date:~0,2%pw%Password%"
    %下方的命令是让程序歇1s，用来防止指令执行太快%
    timeout /T 1 /NOBREAK
    git push origin
    %git命令在这里结束%
) else (
    echo Failed to calculate MD5 value.
)

del %tempfilename%
endlocal
pause