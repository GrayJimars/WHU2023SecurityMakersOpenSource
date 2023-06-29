#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 15
#define QueueLength 10010
#define MAXSHAPEID 65537
#define max(a,b) ((a)>(b)?(a):(b))

typedef struct {
	int x, y;
}xy;
typedef struct {
	xy head;
	int shape[10], shape_id, step;
}Snake;

Snake queue[QueueLength];
int front = -1, rear = -1;

char chess[MAXSIZE][MAXSIZE], visit[MAXSIZE][MAXSIZE][MAXSHAPEID];
int n, m, top = -1, snake_length = 0;
int di[4][2] = { { -1, 0 }, { 0, -1},  { 0, 1 }, { 1, 0 } };//0123上左右下
xy end, start[10];

void shapeidSum(Snake *e){
	int sum = 0;
	for (int i = 2; i <= snake_length; i++) {
		sum *= 4;
		sum += (*e).shape[i];
	}
	(*e).shape_id = sum;
}
void moveTo(Snake* e, int direct) {
	for (int i = snake_length; i > 2; i--) {
		(*e).shape[i] = (*e).shape[i - 1];
	}
	if (snake_length > 1) {
		(*e).shape[2] = direct;
	}
	(*e).head.x += di[direct][0];
	(*e).head.y += di[direct][1];
	shapeidSum(e);
}

int valid(Snake e, int x, int y) {
	if (x >= 0 && x < n
		&& y >= 0 && y < m
		&& chess[x][y] != '#') {
		int flag = 1;
		if(snake_length > 2){
			for (int sx = e.head.x, sy = e.head.y, i = 2; i < snake_length; i++) {
				sx -= di[e.shape[i]][0];
				sy -= di[e.shape[i]][1];
				if (sx == x && sy == y) {
					flag = 0;
					break;
				}
			}
		}
		else {
			for (int sx = e.head.x, sy = e.head.y, i = 2; i <= snake_length; i++) {
				sx -= di[e.shape[i]][0];
				sy -= di[e.shape[i]][1];
				if (sx == x && sy == y) {
					flag = 0;
					break;
				}
			}
		}
		return flag;
	}else {
		return 0;
	}
}

int bfs(Snake snake) {
	rear = (rear + 1) % QueueLength;
	queue[rear] = snake;
	while (front != rear) {
		front = (front + 1) % QueueLength;
		snake = queue[front];
		/*system("cls");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i != snake.head.x || j != snake.head.y) {
					putchar(chess[i][j]);
				}else {
					putchar('%');
				}
			}
			puts("");
		}*/
		if (snake.head.x == end.x && snake.head.y == end.y) {
			return snake.step;
		}
		for (int i = 0; i < 4; i++) {
			Snake e = snake;
			moveTo(&e, i);
			if (valid(snake, snake.head.x + di[i][0], snake.head.y + di[i][1]) 
				&& !visit[e.head.x][e.head.y][e.shape_id]) {
				visit[e.head.x][e.head.y][e.shape_id] = 1;
				e.step = snake.step + 1;
				rear = (rear + 1) % QueueLength;
				queue[rear] = e;
			}
		}
	}
	return -1;
}

int main() {
	Snake snake;
	memset(visit, 0, sizeof(visit));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", chess[i]);
		for (int j = 0; j < m; j++) {
			switch (chess[i][j]) {
			case '@':
				end.x = i;
				end.y = j;
			case '.':case '#':
				break;
			case '1':
				snake.head.x = i;
				snake.head.y = j;
			default:
				snake_length = max(snake_length, chess[i][j] - '0');
				start[chess[i][j] - '0'].x = i;
				start[chess[i][j] - '0'].y = j;
				chess[i][j] = '.';
				break;
			}
		}
	}
	if(snake_length > 1){
		for (int j = 0; j < 4; j++) {
			if (start[2].x + di[j][0] == snake.head.x
				&& start[2].y + di[j][1] == snake.head.y) {
				snake.shape[2] = j;
			}
		}
		for (int i = 3; i <= snake_length; i++) {
			for (int j = 0; j < 4; j++) {
				if (start[i].x + di[j][0] == start[i - 1].x
					&& start[i].y + di[j][1] == start[i - 1].y) {
					snake.shape[i] = j;
				}
			}
		}
	}
	shapeidSum(&snake);
	snake.step = 0;
	printf("%d", bfs(snake));
	return 0;
}