#include "defines.h"

int main() {
	char password[7];
	user u;
	while (Is_First_Use(&u)) {
		First_Use_Setup();
	}

	printf("�����ļ����ڣ���ʼǩ��\n");

	printf("������������룺");
	Input(password, 6);

	printf("����������ɣ���ʼ����md5�ļ�\n");
	md5sum_push(u, password);
	printf("ǩ���ɹ�������ȥ��վ�м��һ�£����ʧ���뷴��\n");
	printf("���س��˳�\n");
	setbuf(stdin, NULL);
	getchar();
	return 0;
}