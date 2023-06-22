#include<stdio.h>

int main() {
    int m, n;
    
    scanf("%d %d", &m, &n);
    
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            putchar('A'+i+j);
        }
        putchar('\n');
    }
    
    return 0;
}