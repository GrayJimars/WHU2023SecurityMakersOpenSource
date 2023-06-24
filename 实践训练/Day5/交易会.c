#include <stdio.h>

int main(){
    int n, m;
    long long quantity[100001] = { 0 };
    scanf("%d %d", &n, &m);
    
    int a, b, c;
    for(int i = 0;i < m;i++){
        scanf("%d %d %d", &a, &b, &c);
        quantity[a] += c;
        quantity[b] += c;
    }
    
    int max = 1;
    for(int i = 2;i < n;i++){
        if(quantity[i] > quantity[max]){
            max = i;
        }
    }
    printf("%d", max);
    return 0;
}