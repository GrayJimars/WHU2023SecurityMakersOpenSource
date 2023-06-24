#include<stdio.h>

int main() {
    int n, SuanTou, rank = 1, temp;
    
    scanf("%d", &n);
    scanf("%d", &SuanTou);
    
    for(int i = 1;i < n;i++) {
        scanf("%d", &temp);
        if(temp > SuanTou) {
            rank++;
        }
    }
    
    printf("%d", rank);
    
    return 0;
}