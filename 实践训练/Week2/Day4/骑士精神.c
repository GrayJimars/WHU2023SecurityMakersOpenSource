#include<stdio.h>
#define SIZE 5
#define MAXSTEP 15
char chess[SIZE][SIZE];
int data_number, step = 0, ok, start_x, start_y;
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

int h() {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i < j) {
				if (chess[i][j] == '0') {
					sum++;
				}
			}
			else if (i > j) {
				if (chess[i][j] == '1') {
					sum++;
				}
			}
			else if (i == j) {
				switch (i) {
				case 0:case 1:
					if (chess[i][j] == '0') {
						sum++;
					}
					break;
				case 3:case 4:
					if (chess[i][j] == '1') {
						sum++;
					}
					break;
				case 2:
					if (chess[i][j] != '*') {
						sum++;
					}
					break;
				}
			}
		}
	}
	return sum;
}
int in(int x, int y) {
	return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}
void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void dfs(int left_step, int empty_x, int empty_y) {
	if (ok) {
		return;
	}
	if (h() == 0) {
		ok = 1;
		return;
	}
	if (h() > left_step) {
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (in(empty_x + di[i][0], empty_y + di[i][1])) {
			swap(&chess[empty_x][empty_y], 
				&chess[empty_x + di[i][0]][empty_y + di[i][1]]); 
			dfs(left_step - 1, empty_x + di[i][0], empty_y + di[i][1]);
			swap(&chess[empty_x][empty_y],
				&chess[empty_x + di[i][0]][empty_y + di[i][1]]);
		}
	}
}

int main() {
	scanf("%d", &data_number);
	while (data_number--) {
		for (int i = 0; i < SIZE; i++) {
			scanf("%s", chess[i]);
			for (int j = 0; j < SIZE; j++) {
				if (chess[i][j] == '*') {
					start_x = i;
					start_y = j;
				}
			}
		}
		ok = 0;
		for (int i = 1; i <= MAXSTEP; i++) {
			dfs(i, start_x, start_y);
			if (ok) {
				printf("%d\n", i);
				break;
			}
		}
		if (!ok) {
			printf("-1\n");
		}
	}
	return 0;
}