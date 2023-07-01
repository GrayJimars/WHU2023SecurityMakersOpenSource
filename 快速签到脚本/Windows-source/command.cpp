#include "defines.h"

void init(char* Classroom, char* Branch) {
	char command[256];
	printf("即将开始初始化本地git\n");

	strcpy(command, "git clone git@se.jisuanke.com:whu2023/");
	strcat(command, Classroom);
	strcat(command, ".git");

	system(command);
	printf("git初始化完毕\n");

	strcpy(command, "cd ");
	strcat(command, Classroom);
	strcat(command, " && ");
	strcat(command, "git config --global --add safe.directory *");
	strcat(command, " && ");
	strcat(command, "git checkout -b ");
	strcat(command, Branch);

	system(command);
	printf("切换到%s分支\n", Branch);

	strcpy(command, "cd ");
	strcat(command, Classroom);
	strcat(command, " && ");
	strcat(command, "git fetch --all");
	strcat(command, " && ");
	strcat(command, "git reset --hard origin/");
	strcat(command, Branch);

	system(command);
	printf("同步远端%s分支\n", Branch);
}

void md5sum_push(user u, char* password) {
	char outputfile[32] = { 0 }, code[32], command[512], t[2] = {'%', '\0'};
	time_t current_time;
	time(&current_time);
	struct tm* format_time;
	format_time = gmtime(&current_time);

	snprintf(outputfile, 32, "%d-%02d-%02d"
		, 1900 + format_time->tm_year
		, 1 + format_time->tm_mon
		, format_time->tm_mday);

	strcpy(code, u.Identity);
	strcat(code, password);
	strcat(code, u.Classroom);
	char tempfile[32];
	strcpy(tempfile, u.Classroom);
	strcat(tempfile, "\\temp.txt");
	FILE* fp;
	fp = fopen(tempfile, "w");
	fprintf(fp, code);
	fclose(fp);

	strcpy(command, "cd ");
	strcat(command, u.Classroom);
	strcat(command, " && ");
	strcat(command, "git checkout -b ");
	strcat(command, u.Branch);

	system(command);
	printf("切换到%s分支\n", u.Branch);

	strcpy(command, "cd ");
	strcat(command, u.Classroom);
	strcat(command, " && ");
	strcat(command, "git fetch --all");
	strcat(command, " && ");
	strcat(command, "git reset --hard origin/");
	strcat(command, u.Branch);

	system(command);
	printf("同步远端%s分支\n", u.Branch);

	strcpy(command, "cd ");
	strcat(command, u.Classroom);
	strcat(command, " && ");
	strcat(command, "FOR /F ");
	strcat(command, t);
	strcat(command, "a IN ('CertUtil -hashfile temp.txt MD5 ^| find /v \":\" ^| findstr /r \"^[0-9a-fA-F]*$\"') DO ( echo|set /p=");
	strcat(command, t);
	strcat(command, "a > ");
	strcat(command, outputfile);
	strcat(command, " )");

	system(command);
	printf("MD5值已经被写入%s\n", outputfile);

	strcpy(command, "cd ");
	strcat(command, u.Classroom);
	strcat(command, " && ");
	strcat(command, "del ");
	strcat(command, "temp.txt");
	system(command);//删除temp.txt


	printf("即将开始进行推送\n");

	strcpy(command, "cd ");
	strcat(command, u.Classroom);
	strcat(command, " && ");
	strcat(command, "git add ");
	strcat(command, outputfile);

	system(command);
	printf("文件追踪完毕\n");

	strcpy(command, "cd ");
	strcat(command, u.Classroom);
	strcat(command, " && ");
	strcat(command, "git commit -m \"密码:");
	strcat(command, password);
	strcat(command, "\"");

	system(command);
	printf("文件提交完毕\n");

	strcpy(command, "cd ");
	strcat(command, u.Classroom);
	strcat(command, " && ");
	strcat(command, "git push origin ");
	strcat(command, u.Branch);

	system(command);
	printf("文件提交完毕\n");
}