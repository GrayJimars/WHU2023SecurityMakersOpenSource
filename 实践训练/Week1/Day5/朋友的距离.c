#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, matrix[100][100];
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d", &matrix[i][j]);
            if(i > j){
                if(matrix[i][j] > matrix[j][i]){
                    matrix[j][i] = matrix[i][j];
                }else{
                    matrix[i][j] = matrix[j][i];
                }
            }
        }
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
	return 0;
}