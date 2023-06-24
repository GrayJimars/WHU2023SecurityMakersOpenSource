#include<stdio.h>

int di[2][2] = { { 1, -1 }, { -1, 1 } };
int matrix[100][100], m, n, direct = 1, snake[2] = { 0, 0 };

void Go(){
    while(snake[0] + di[direct][0] >= 0
          && snake[0] + di[direct][0] < m 
          && snake[1] + di[direct][1] >= 0 
          && snake[1] + di[direct][1] < n){
        printf("%d ", matrix[snake[0]][snake[1]]);
        snake[0] += di[direct][0];
        snake[1] += di[direct][1];
    }
}

void Redirect(){
    printf("%d ", matrix[snake[0]][snake[1]]);
    if((snake[0] == 0 || snake[0] == m - 1) && snake[1] != n - 1){
        snake[1]++;
        direct = !direct;
    }else if(snake[1] == 0 || snake[1] == n - 1){
        snake[0]++;
        direct = !direct;
    }
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    while(snake[0] < m && snake[1] < n){
        Redirect();
        Go();
    }
    
    return 0;
}