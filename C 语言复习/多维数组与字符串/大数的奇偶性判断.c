#include<stdio.h>
#include<string.h>
#define MAXSIZE 10010
int main () {
	char s[MAXSIZE]= {0};
	gets(s);int f;
	int flag=0;
	for(int i=0; i<MAXSIZE; i++) {
		if(s[i+1]==0) {
			f=i;
			break;
		}
	}
	if((s[f]-48)%2==0) {
		flag=1;
	}
	//puts(s);
	if(flag) {
		printf("YES");
	} else {
		printf("NO");
	}
}