#include<stdio.h>
int main(){
    double r1,r2,pi=3.14;
    scanf("%lf %lf",&r1,&r2);
    
    printf("%.6lf",pi*(r1*r1-r2*r2));
    return 0;
}