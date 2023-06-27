#include <stdio.h>

#define QueueLength 5010

typedef struct {
    int x;
    int y;
    int Chakra;
    int step;
}ElemType;

ElemType queue[40010];
int front = -1, rear = -1;
int di[4][2] = { { 0, 1 }, { 0, -1},  { 1, 0 }, { -1, 0 } };

int visit[200][200][10] = {0};
int valid(int M, int N, int x, int y, int Chakra) {
    return x >= 0 && x < M
        && y >= 0 && y < N
        && !visit[x][y][Chakra];
}

int bfs(char maze[200][200], int M, int N, int start[], int end[], int T) {
    ElemType now;
    now.x = start[0];
    now.y = start[1];
    now.Chakra = T;
    now.step = 0;
    rear = (rear + 1) % QueueLength;
    queue[rear] = now;
    while (front != rear) {
        front = (front + 1) % QueueLength;
        now = queue[front];
        if (now.x == end[0] && now.y == end[1]) {
            return now.step;
        }
        for (int i = 0; i < 4; i++) {
            if (valid(M, N, now.x + di[i][0], now.y + di[i][1]
                , now.Chakra - (maze[now.x + di[i][0]][now.y + di[i][1]] == '#'))) {
                ElemType e;
                e.x = now.x + di[i][0];
                e.y = now.y + di[i][1];
                e.step = now.step + 1;
                e.Chakra = now.Chakra;
                if (maze[e.x][e.y] == '#') {
                    if (e.Chakra > 0) {
                        e.Chakra--;
                    }
                    else {
                        continue;
                    }
                }
                visit[e.x][e.y][e.Chakra] = 1;
                rear = (rear + 1) % QueueLength;
                queue[rear] = e;
            }
        }
    }
    return -1;
}

int main() {
    int M, N, T, start[2], end[2];
    char maze[200][200];
    scanf("%d %d %d", &M, &N, &T);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            while ((maze[i][j] = getchar()) == '\n');
            if (maze[i][j] == '@') {
                start[0] = i;
                start[1] = j;
            }
            else if (maze[i][j] == '+') {
                end[0] = i;
                end[1] = j;
            }
        }
    }
    printf("%d", bfs(maze, M, N, start, end, T));
    return 0;
}