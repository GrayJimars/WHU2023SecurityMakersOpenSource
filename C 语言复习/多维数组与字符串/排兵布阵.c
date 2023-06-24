#include <stdio.h>

int main() {
    int m, n, sum = 0, number;
    
    scanf("%d %d", &m, &n);
    
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            scanf("%d", &number);
            if(i == 0 || j ==0 || i == m - 1 || j == n - 1) {
                sum += number;
            }
        }
    }
    printf("%d", sum);
    return 0;
}