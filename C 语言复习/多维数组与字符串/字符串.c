#include<stdio.h>
int main() {
	char str[1010];
	scanf("%s", str);
	int j = 0;
	while(str[j]) {
        str[j] = str[j] >= 'A' && str[j] <= 'Z' ? (str[j] - 'A' + 1) % 26 + 'A' : str[j];
        str[j] = str[j] >= 'a' && str[j] <= 'z' ? (str[j] - 'a' + 1) % 26 + 'a' : str[j];
		j++;
	}
	puts(str);
    return 0;
}