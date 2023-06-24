#include<stdio.h>
#include<string.h>
#define MAXSIZE 1010
int main() {
	char str[MAXSIZE]= {0};
	gets(str);
	char ch;
	int j=0;
	while(str[j]) {
		ch=str[j];
		if(ch >= 'a' && ch < 'z' || ch >= 'A' && ch < 'Z') {
			str[j]++;
		}
		if(ch=='z' || ch=='Z') {
			str[j]-=25;
		}
		j++;
	}
	printf("%s",str);

}