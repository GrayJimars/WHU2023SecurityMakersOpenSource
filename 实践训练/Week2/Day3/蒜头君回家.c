#include <stdio.h>
#include <string.h>
#define QueueLength 5010

typedef struct {
    int x;
    int y;
    int key;
    int step;
}ElemType;

ElemType queue[4000010];
int front = -1, rear = -1;
int di[4][2] = { { 0, 1 }, { 0, -1},  { 1, 0 }, { -1, 0 } };
char maze[2010][2010];
int visit[2000][2000] = { 0 }, visitk[2000][2000] = { 0 };

int valid(char maze[2010][2010], int M, int N, ElemType e) {
    if (e.key) {
        return e.x >= 0 && e.x < M
            && e.y >= 0 && e.y < N
            && maze[e.x][e.y] != '#'
            && !visitk[e.x][e.y];
    }
    else {
        return e.x >= 0 && e.x < M
            && e.y >= 0 && e.y < N
            && maze[e.x][e.y] != '#'
            && !visit[e.x][e.y];
    }
}

int bfs(char maze[2010][2010], int M, int N, int start[]) {
    ElemType now;
    now.x = start[0];
    now.y = start[1];
    now.key = 0;
    now.step = 0;
    visit[now.x][now.x] = 1;
    rear = (rear + 1) % QueueLength;
    queue[rear] = now;
    while (front != rear) {
        front = (front + 1) % QueueLength;
        now = queue[front];
        if (maze[now.x][now.y] == 'T' && now.key) {
            return now.step;
        }
        if (maze[now.x][now.y] == 'P') {
            now.key = 1;
            visitk[now.x][now.y] = 1;
        }
        for (int i = 0; i < 4; i++) {
            ElemType e;
            e.x = now.x + di[i][0];
            e.y = now.y + di[i][1];
            e.step = now.step + 1;
            e.key = now.key;
            if (valid(maze, M, N, e)) {
                if (e.key) {
                    visitk[e.x][e.y] = 1;
                }
                else {
                    visit[e.x][e.y] = 1;
                }
                rear = (rear + 1) % QueueLength;
                queue[rear] = e;
            }
        }
    }
    return -1;
}


int main() {
    int n, m, start[2];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            while ((maze[i][j] = getchar()) == '\n');
            if (maze[i][j] == 'S') {
                start[0] = i;
                start[1] = j;
            }
        }
    }
    printf("%d", bfs(maze, n, m, start));
    return 0;
}