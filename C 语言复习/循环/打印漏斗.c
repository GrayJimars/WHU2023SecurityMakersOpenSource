#include<stdio.h>
int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i = 0;i < n * 2 + 1;i++) {
        if(i < n) {
            for(int j = 0;j < i;j++) {
                putchar(' ');
            }
            for(int j = 0;j < (n - i) * 2 + 1;j++) {
                putchar('A');
            }
            for(int j = 0;j < i;j++) {
                putchar(' ');
            }
        }else {
            for(int j = 0;j < n * 2 - i;j++) {
                putchar(' ');
            }
            for(int j = 0;j < (i - n) * 2 + 1;j++) {
                putchar('A');
            }
            for(int j = 0;j < n * 2 - i;j++) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    
    return 0;
}