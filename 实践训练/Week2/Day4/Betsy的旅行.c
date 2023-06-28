#include <stdio.h>
#include <stdlib.h>
#define maxn 9

int visit[maxn][maxn] = { 0 }, count = 0, n;
int di[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int access_number[maxn][maxn] = { 0 };

int in(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
void visit_block(int x, int y) {
	access_number[x - 1][y]--;
	access_number[x + 1][y]--;
	access_number[x][y - 1]--;
	access_number[x][y + 1]--;
}
void visit_return(int x, int y) {
	access_number[x - 1][y]++;
	access_number[x + 1][y]++;
	access_number[x][y - 1]++;
	access_number[x][y + 1]++;
}

void dfs(int step, int x, int y) {
	visit[x][y] = 1;
	if (x == n && y == 1) {
		if (step == n * n) {
			count++;
		}
		visit[x][y] = 0;
		return;
	}
	visit_block(x, y);
	int must_number = 0, must_x, must_y;
	for (int i = 0; i < 4; i++) {
		int tx = x + di[i][0], ty = y + di[i][1];
		if (access_number[tx][ty] == 1 && !visit[tx][ty] && in(tx, ty)) {
			must_number++;
			must_x = tx;
			must_y = ty;
		}
	}
	if (must_number) {
		dfs(step + 1, must_x, must_y);
	}else{
		for (int i = 0; i < 4; i++) {
			int tx = x + di[i][0], ty = y + di[i][1];
			if (!visit[tx][ty] && in(tx, ty)) {
				dfs(step + 1, tx, ty);
			}
		}
	}
	visit[x][y] = 0;
	visit_return(x, y);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			access_number[i][j] = 4 - (i == 1 || i == n) - (j == 1 || j == n);
		}
	}
	access_number[n][1]++;
	dfs(1, 1, 1);
	printf("%d", count);
	return 0;
}