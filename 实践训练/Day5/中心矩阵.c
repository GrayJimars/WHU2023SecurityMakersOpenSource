#include <stdio.h>
int Min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ",Min(Min(Min(i + 1, j + 1) , n - i) , n - j));
        }
        puts("");
    }
    return 0;
}