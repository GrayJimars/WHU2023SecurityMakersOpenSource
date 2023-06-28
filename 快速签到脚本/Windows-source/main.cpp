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
	return 0;
}