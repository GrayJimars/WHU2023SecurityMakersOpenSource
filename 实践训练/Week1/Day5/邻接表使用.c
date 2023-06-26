#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, matrix[100][101] = { 0 };
    scanf("%d %d", &n, &m);
    
    int a, x, y;
    for(int i = 0;i < m;i++){
        scanf("%d %d %d", &a, &x, &y);
        if(a){
            matrix[x][matrix[x][100]++] = y;
            matrix[y][matrix[y][100]++] = x;
        }else{
            matrix[x][matrix[x][100]++] = y;
        }
    }
    
    for(int i = 0;i < n;i++){
        printf("%d:", i);
        for(int j = matrix[i][100] - 1;j >= 0;j--){
            printf(" %d", matrix[i][j]);
        }
        puts("");
    }
	return 0;
}