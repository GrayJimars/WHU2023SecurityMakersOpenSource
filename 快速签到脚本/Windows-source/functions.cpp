#include "defines.h"

//�޳����루���֣�
void Input(char str[], int mustlen)
{
	char ch;//�����ַ�����
	int i;//�ڱ�

	i = 0;
	while (1)
	{
		ch = _getch();//��ȡ�����ַ�

		if (ch >= '0' && ch <= '9' 
			|| ch >= 'a' && ch <= 'z' 
			|| ch >= 'A' && ch <= 'Z')//�����������ֻ���ĸʱ
		{
			if (i < mustlen)//���û������󳤶�
			{
				str[i] = ch;//�����ַ���
				putch(ch);//��ʾ
				i++;//iÿ�μ�1
			}
		}

		if (ch == 8 && i > 0)////�û������˸�ʱ��i>0ʱ
		{
			i--;//�˸�
			printf("\b \b");
		}

		if (ch == '\r' && i == mustlen)//����س��Ҵﵽ�涨�������������
			break;
	}
	str[i] = '\0';//ĩβ���Ͻ�ֹ��
	putchar('\n');
}

//�Ƿ�Ϊ��һ��ʹ��
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

//��һ��ʹ��������Ϣ
void First_Use_Setup() {
	printf("�����ǵ�һ��ʹ�ã���ʼ������Ϣ\n");
	user e;
	bool ok = false;
	while(!ok){
		printf("���������ѧ�ţ�");
		Input(e.Identity, 13);
		printf("��������Ľ��ң�");
		Input(e.Classroom, 3);
		printf("��������ķ�֧����");
		gets_s(e.Branch, 63);
		printf("���ѧ��Ϊ%s������Ϊ%s\n��֧��Ϊ%s\n", e.Identity, e.Classroom, e.Branch);
		printf("ȷ�ϼ���(y/n)\n");
		if (getchar() == 'y') {
			ok = true;
		}
	}

	init(e.Classroom, e.Branch);

	FILE* fp;
	fp = fopen("Userdata.bin", "wb");
	fwrite(&e, sizeof(user), 1, fp);
	fclose(fp);

	printf("�������\n");
}