#include <stdio.h>
int Rvisit[9][9] = { 0 }, Cvisit[9][9] = { 0 }, Nvisit[3][3][9] = { 0 }, ok = 0;
void dfs(char chess[9][9], int x, int y) {
    if (ok) {
        return;
    }
    if (y == 9) {
        dfs(chess, x + 1, 0);
        return;
    }
    if (chess[x][y] != '*') {
        dfs(chess, x, y + 1);
        return;
    }
    for (int i = 0; i < 9; i++) {
        if (!Rvisit[x][i] && !Cvisit[y][i] && !Nvisit[x / 3][y / 3][i]) {
            Rvisit[x][i] = 1;
            Cvisit[y][i] = 1;
            Nvisit[x / 3][y / 3][i] = 1;
            chess[x][y] = i + '1';
            if (x == 8 && y == 8) {
                ok = 1;
                return;
            }
            dfs(chess, x, y + 1);
            if (ok) {
                return;
            }
            chess[x][y] = '*';
            Rvisit[x][i] = 0;
            Cvisit[y][i] = 0;
            Nvisit[x / 3][y / 3][i] = 0;
        }
    }
}

int main() {
    char chess[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char ch = getchar();
            while (ch == '\n' || ch == ' ')ch = getchar();
            chess[i][j] = ch;
            if (chess[i][j] != '*') {
                Rvisit[i][chess[i][j] - '1'] = 1;
                Cvisit[j][chess[i][j] - '1'] = 1;
                Nvisit[i / 3][j / 3][chess[i][j] - '1'] = 1;
            }
        }
    }
    dfs(chess, 0, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", chess[i][j]);
        }
        puts("");
    }
    return 0;
}