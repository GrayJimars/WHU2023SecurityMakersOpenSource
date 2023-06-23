#include <stdio.h>

int main() {
    int L, M, road[10010] = { 0 }, start, end, sum;
    scanf("%d %d", &L, &M);
    sum = L + 1;
    
    for (int i = 0;i < M;i++) {
        scanf("%d %d", &start, &end);
        for (int j = start;j <= end;j++) {
            road[j] = -1;
        }
    }
    
    for (int i = 0;i <= L;i++) {
        sum += road[i];
    }
    
    printf("%d", sum);
    
    return 0;
}