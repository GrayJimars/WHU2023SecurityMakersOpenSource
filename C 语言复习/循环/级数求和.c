#include<stdio.h>

int main() {
    int K, n = 1;
    double sum = 0;
    
    scanf("%d", &K);
    
    while(sum < K) {
        sum += 1 / (double)n;
        n++;
    }
    
    n--;
    
    printf("%d", n);
    
    return 0;
}