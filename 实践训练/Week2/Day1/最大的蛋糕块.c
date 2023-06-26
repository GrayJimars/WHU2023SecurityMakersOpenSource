#include<stdio.h>
int di[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int in(int x, int y, int R, int C){
    return x >= 0 && x < R && y >= 0 && y < C;
}

int dfs(char maze[1010][1010], int x, int y, int R, int C){
    if(!in(x, y, R, C) || maze[x][y] == '.'){
        return 0;
    }
    int count = 0;
    maze[x][y] = '.';
    for(int i = 0;i < 4;i++){
        count += dfs(maze, x + di[i][0], y + di[i][1], R, C);
    }
    return 1 + count;
}

int main(){
    int  R, C, max = 0, temp;
    char maze[1010][1010];
    scanf("%d %d", &R, &C);
    for(int i = 0;i < R;i++){
        scanf("%s", maze[i]);
    }
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            if(maze[i][j] == '#'){
                if((temp = dfs(maze, i, j, R, C)) > max){
                    max = temp;
                }
            }
        }
    }
    printf("%d", max);
    return 0;
}