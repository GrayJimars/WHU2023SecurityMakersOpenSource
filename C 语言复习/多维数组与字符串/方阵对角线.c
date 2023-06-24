#include <stdio.h>

int main() {
    int n, number;
    
    scanf("%d", &n);
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            scanf("%d", &number);
            if(i == j) {
                printf("%d\n", number);
            }
        }
    }
    return 0;
}