#include <stdio.h>

typedef struct{
    char p1[21];
    char p2[21];
}Relation;

int main(){
    Relation relation[100];
    int n, m;
    scanf("%d", &n);
    
    for(int i = 0;i < n;i++){
        scanf("%s %s", relation[i].p1, relation[i].p2);
    }
    
    scanf("%d", &m);
    
    char p1[21], p2[21];
    int find;
    for(int i = 0;i < m;i++){
        find = 0;
        scanf("%s %s", p1, p2);
        for(int j = 0;j < n;j++){
            if((!strcmp(relation[j].p1, p1) 
                && !strcmp(relation[j].p2, p2)) 
               || (!strcmp(relation[j].p1, p2) 
                   && !strcmp(relation[j].p2, p1))){
                find = 1;
            }
        }
        if(find){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}