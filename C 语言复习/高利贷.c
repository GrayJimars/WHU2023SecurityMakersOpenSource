#include<stdio.h>
int main(){
    double x;
    int n;
    scanf("%lf %d",&x,&n);
    
    while(n){
        x*=1.06;
        n--;
    }
    
    printf("%d",(int)x);
    return 0;
}