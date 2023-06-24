#include<stdio.h>

int main(){
    int h,m,s,t;
    float rate;
    char time[]="am";
    
    scanf("%d %d %d %d",&h,&m,&s,&t);
    rate=(float)t/864;
    t=(t+3600*h+60*m+s)%86400;
    
    h=(t/3600)%24;
    m=(t/60%60)%60;
    s=(t%60)%60;
    
    if(h<12){
        h%=12;
        if(!h){
            h=12;
        }
    }else{
        h=(h-1)%12+1;
        time[0]='p';
    }
    
    printf("%d:%d:%d%s\n%.2f%%",h,m,s,time,rate);
    
    return 0;
}