#include<stdio.h>
#include<math.h>
void transfer(long long number,char* target) {
	int j=31;
	while(number >= 2) {
		target[j]=(number%2+48);
		number/=2;
		j--;
	}
	if(number==1) {
		target[j]=(number%2+48);
	}
}
int main() {
	long long number;
	scanf("%lld",&number);
	char target[33];
	target[32]='\0';
	for(int i=0; i<32; i++)target[i]='0';
	transfer(number,target);

	char transfer[33];

	for(int i=0; i<16; i++) {
		transfer[i+16]=target[i];
		transfer[i]=target[i+16];
	}
	//strcat(low,high);

	double sum=0;
	for(int i=31; i>=0; i--) {
		sum+=pow(2,31-i)*(transfer[i]-48);
	}
	printf("%.0lf\n",sum);
}