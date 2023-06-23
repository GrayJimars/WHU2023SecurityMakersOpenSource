#include <stdio.h>

int main() {
    int number, n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            scanf("%d", &number);
            if(j <= i) {
                printf("%d ", number);
            }
        }
        puts("");
    }
    return 0;
}