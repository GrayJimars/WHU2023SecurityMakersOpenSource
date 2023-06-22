# 方便了？好像也没怎么方便
武大2023网安创客快速签到  
WindowsVerA适用于Windows系统且时间格式为2023/06/21这种  
WindowsVerB适用于Windows系统且时间格式为21/06/2023这种  
MacOSVer适用于MacOS  
Windows时间格式的查看需要看你电脑屏幕右下角的显示格式  

使用之前必须配置过git的origin变量  

# WindowsVer使用方法：  
（下列用法针对Windows系统，测试时用的Win11）  
先选择一个合适的版本  
然后把.bat放在你要签到的项目文件夹里  
例如  
[![.bat位置示例](https://img1.imgtp.com/2023/06/22/dKIchuTo.png "Location example")]  
运行.bat  
输入相关信息  
会自动按照你输入的信息生成md5码并保存为xxxx/xx/xx的文件  
然后  
git add xxxx/xx/xx  
git commit -m "<日期>pw<密码>"  
git pull  
git push origin  
# WindowsVer目前问题  
签到时由于每个人git配置、系统环境的不同可能失败  
总之先检查信息有没有输入正确  
然后检查一下你右下角的系统日期是不是之前提到的格式  
最后看看你自己之前签到是不是用的先git add然后commit然后pull然后push origin  
如果你之前不是这样子签到的，可以用文本编辑器自己改一下.bat文件  
把从22行开始的几行git命令改成你自己用的就好  
