#include "defines.h"

int main() {
	char password[7];
	user u;
	while (Is_First_Use(&u)) {
		First_Use_Setup();
	}

	printf("配置文件存在，开始签到\n");

	printf("请输入今日密码：");
	Input(password, 6);

	printf("密码设置完成，开始生成md5文件\n");
	md5sum_push(u, password);
	printf("签到成功！建议去网站中检查一下，如果失败请反馈\n");
	printf("按回车退出\n");
	setbuf(stdin, NULL);
	getchar();
	return 0;
}