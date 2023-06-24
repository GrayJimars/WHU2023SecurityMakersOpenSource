#include <stdio.h>

int Ackman(int m, int n){
    if(m == 0){
        return n + 1;
    }else if(m > 0 && n == 0){
        return Ackman(m - 1, 1);
    }else if(m > 0 && n > 0){
        return Ackman(m - 1, Ackman(m, n - 1));
    }
}

int main(){
    int m, n;
    scanf("%d %d",&m, &n);
    printf("%d", Ackman(m, n));
    return 0;
}