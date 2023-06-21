#include<stdio.h>

int Peaches(int n){
    if(n == 1){
        return 1;
    }else{
        return 2 * (Peaches(n - 1) + 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", Peaches(n));
    return 0;
}
