#include<stdio.h>
int di[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int in(int x, int y, int R, int C){
    return x >= 0 && x < R && y >= 0 && y < C;
}

void dfs(char maze[1010][1010], int x, int y, int R, int C){
    if(!in(x, y, R, C) || maze[x][y] == '.'){
        return;
    }
    maze[x][y] = '.';
    for(int i = 0;i < 4;i++){
        dfs(maze, x + di[i][0], y + di[i][1], R, C);
    }
}

int main(){
    int  R, C, count = 0;
    char maze[1010][1010];
    scanf("%d %d", &R, &C);
    for(int i = 0;i < R;i++){
        scanf("%s", maze[i]);
    }
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            if(maze[i][j] == '#'){
                dfs(maze, i, j, R, C);
                count++;
            }
        }
    }
    printf("%d", count);
    return 0;
}