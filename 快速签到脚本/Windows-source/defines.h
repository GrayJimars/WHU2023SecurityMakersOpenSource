#pragma once
#ifndef DEFINES_HEAD

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

typedef struct {
	char Identity[14], Classroom[4], Branch[64];
}user;

//�޳����루���ֻ���ĸ��
void Input(char str[], int mustlen);

//�Ƿ�Ϊ��һ��ʹ��
bool Is_First_Use(user* u);

//��һ��ʹ��������Ϣ
void First_Use_Setup();

//��ʼ��
void init(char* Classroom, char* Branch);

//��ȡmd5�ļ���push
void md5sum_push(user u, char* password);

#endif // !DEFINES_HEAD
