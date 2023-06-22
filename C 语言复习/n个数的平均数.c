#include<stdio.h>

int main() {
    int n, sum = 0, i, temp;
    float result;
    
    scanf("%d", &n);
    
    for(i = 0;i < n;i++) {
        scanf("%d", &temp);
        sum += temp;
    }
    
    result = (float)sum / n;
    
    printf("%.2f", result);
    
    return 0;
}