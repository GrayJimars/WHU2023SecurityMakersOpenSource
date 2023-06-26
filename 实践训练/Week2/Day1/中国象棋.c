#include<stdio.h>

#define ROW 10
#define COL 9
int visit[ROW][COL] = { 0 };
int di[8][2] = {
    { -2, 1 }, 
    { -1, 2 }, 
    { 1, 2 }, 
    { 2, 1 }, 
    { 2, -1 }, 
    { 1, -2 }, 
    { -1, -2 },
    { -2, -1 }
};

int in(int x, int y){
    return x >= 0 && x < ROW && y >= 0 && y < COL;
}

int dfs(char matrix[ROW][COL], int x, int y){
    if(!in(x, y) || matrix[x][y] == '#' || visit[x][y]){
        return 0;
    }else if(matrix[x][y] == 'T'){
        return 1;
    }
    visit[x][y] = 1;
    int ok = 0;
    for(int i = 0;i < 8;i++){
        ok = ok || dfs(matrix, x + di[i][0], y + di[i][1]);
        if(ok){
            break;
        }
    }
    return ok;
}

int main(){
    char matrix[ROW][COL];
    int start[2];
    for(int i = 0;i < ROW;i++){
        for(int j = 0;j < COL;j++){
            while((matrix[i][j] = getchar()) == '\n');
            if(matrix[i][j] == 'S'){
                start[0] = i;
                start[1] = j;
            }
        }
    }
    if(dfs(matrix, start[0], start[1])){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}