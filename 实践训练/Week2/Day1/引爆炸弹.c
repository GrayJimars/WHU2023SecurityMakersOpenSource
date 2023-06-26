#include<stdio.h>

#define MAXSIZE 510

void dfs(int matrix[MAXSIZE][MAXSIZE], int x, int y, int n, int m) {
    matrix[x][y] = 0;
    for (int i = 0; i < m; i++) {
        if (matrix[x][i]) {
            dfs(matrix, x, i, n, m);
        }
    }
    for (int i = 0; i < n; i++) {
        if (matrix[i][y]) {
            dfs(matrix, i, y, n, m);
        }
    }
}

int main() {
    int matrix[MAXSIZE][MAXSIZE], bombs[MAXSIZE * MAXSIZE][2], n, m, top = 0, count = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &matrix[i][j]);
            if (matrix[i][j]) {
                bombs[top][0] = i;
                bombs[top++][1] = j;
            }
        }
    }
    for (int i = 0; i < top; i++) {
        if (matrix[bombs[i][0]][bombs[i][1]]) {
            dfs(matrix, bombs[i][0], bombs[i][1], n, m);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}