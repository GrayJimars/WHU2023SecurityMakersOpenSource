#include <stdio.h>

int main(){
    int cownum[101] = { 0 }, n, cow;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", &cow);
        cownum[cow]++;
    }
    
    int oddsum = 0, evensum = 0;
    for(int i = 1;i <= 100;i++){
        if(i % 2 == 1){
            oddsum += cownum[i];
        }else{
            evensum += cownum[i];
        }
    }
    
    if(oddsum == evensum){
        printf("%d", n);
    }else if(evensum > oddsum){
        printf("%d", oddsum * 2 + 1);
    }else{
        while(oddsum > evensum + 1){
            oddsum -= 2;
            evensum++;
        }
        if(oddsum == evensum){
            printf("%d", oddsum + evensum);
        }else{
            printf("%d", evensum * 2 - 1);
        }
    }
    return 0;
}