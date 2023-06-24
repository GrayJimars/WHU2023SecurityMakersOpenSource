#include<stdio.h>
int main(){
    int t,h,m,s;
    char str[]="00:00:00";
    scanf("%d",&t);
    h=(t/3600);
    m=(t/60%60);
    s=(t%60);
    
    str[0]+=((h>12?h-12:h)/10);
    str[1]+=((h>12?h-12:h)%10);
    str[3]+=(m/10);
    str[4]+=(m%10);
    str[6]+=(s/10);
    str[7]+=(s%10);
    
    printf("%s ",str);
    if(h<12){
        printf("am");
    }else if(h<13){
        printf("midnoon");
    }else{
        printf("pm");
    }
    return 0;
}