#include<stdio.h>
int main(){
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},
    year,month,day;
    scanf("%d %d %d",&year,&month,&day);
    
    if((year%100!=0 && year%4==0) || year%400==0){
        days[2]++;
    }
    
    if(day==1){
        if(month==1){
            printf("%d 12 31\n",year-1);
        }
        else{
            printf("%d %d %d\n",year,month-1,days[month-1]);
        }
        printf("%d %d %d",year,month,day+1);
    }else if(day==days[month]){
        printf("%d %d %d\n",year,month,day-1);
        if(month==12){
            printf("%d 1 1",year+1);
        }else{
            printf("%d %d 1",year,month+1);
        }
    }else{
        printf("%d %d %d\n",year,month,day-1);
        printf("%d %d %d",year,month,day+1);
    }
    
    return 0;
}