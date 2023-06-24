#include<stdio.h>

int main() {
    char max = 'A', temp;
    int n;
    
    scanf("%d", &n);
    
    for(int i = 0;i < n;i++) {
        getchar();
        temp = getchar();
        if(temp > max) {
            max = temp;
        }
    }
    
    putchar(max+1);
    
    return 0;
}