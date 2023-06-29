#include "defines.h"

//限长输入（数字）
void Input(char str[], int mustlen)
{
	char ch;//输入字符缓存
	int i;//哨兵

	i = 0;
	while (1)
	{
		ch = _getch();//获取输入字符

		if (ch >= '0' && ch <= '9' 
			|| ch >= 'a' && ch <= 'z' 
			|| ch >= 'A' && ch <= 'Z')//输入正常数字或字母时
		{
			if (i < mustlen)//如果没超过最大长度
			{
				str[i] = ch;//加入字符串
				putch(ch);//显示
				i++;//i每次加1
			}
		}

		if (ch == 8 && i > 0)////用户输入退格时且i>0时
		{
			i--;//退格
			printf("\b \b");
		}

		if (ch == '\r' && i == mustlen)//输入回车且达到规定长度则输入完毕
			break;
	}
	str[i] = '\0';//末尾加上截止符
	putchar('\n');
}

//是否为第一次使用
bool Is_First_Use(user* u) {
	FILE* fp;
	if (fp = fopen("Userdata.bin", "rb")) {
		fread(u, sizeof(user), 1, fp);
		fclose(fp);
		return false;
	}
	else {
		return true;
	}
}

//第一次使用配置信息
void First_Use_Setup() {
	printf("发现是第一次使用，开始配置信息\n");
	user e;
	bool ok = false;
	while(!ok){
		printf("请输入你的学号：");
		Input(e.Identity, 13);
		printf("请输入你的教室：");
		Input(e.Classroom, 3);
		printf("请输入你的分支名：");
		gets_s(e.Branch, 63);
		printf("你的学号为%s，教室为%s\n分支名为%s\n", e.Identity, e.Classroom, e.Branch);
		printf("确认继续(y/n)\n");
		if (getchar() == 'y') {
			ok = true;
		}
	}

	init(e.Classroom, e.Branch);

	FILE* fp;
	fp = fopen("Userdata.bin", "wb");
	fwrite(&e, sizeof(user), 1, fp);
	fclose(fp);

	printf("配置完成\n");
}