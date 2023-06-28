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

//限长输入（数字或字母）
void Input(char str[], int mustlen);

//是否为第一次使用
bool Is_First_Use(user* u);

//第一次使用配置信息
void First_Use_Setup();

//初始化
void init(char* Classroom, char* Branch);

//获取md5文件并push
void md5sum_push(user u, char* password);

#endif // !DEFINES_HEAD
