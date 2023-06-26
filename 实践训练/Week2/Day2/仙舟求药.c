#include <stdio.h>

#define QueueLength 5010

typedef struct{
    int x;
    int y;
    int step;
}ElemType;

ElemType queue[5010];
int front = -1, rear = -1;
void enqueue(ElemType e) {
    rear = (rear + 1) % QueueLength;
    queue[rear] = e;
}
void dequeue(ElemType *e) {
    front = (front + 1) % QueueLength;
    *e = queue[front];
}

int di[4][2] = { { 0, 1 }, { 0, -1},  { 1, 0 }, { -1, 0 } };

int valid(char maze[20][20], int M, int N, int x, int y) {
    return x >= 0 && x < M 
        && y >= 0 && y < N
        && maze[x][y] != '#';
}

int bfs(char maze[20][20], int M, int N, int start[], int end[]) {
    ElemType now;
    now.x = start[0];
    now.y = start[1];
    now.step = 0;
    enqueue(now);
    while (front != rear) {
        dequeue(&now);
        if (now.x == end[0] && now.y == end[1]) {
            return now.step;
        }
        maze[now.x][now.y] = '#';
        for(int i = 0;i < 4;i++){
            if(valid(maze, M, N, now.x + di[i][0], now.y + di[i][1])){
                ElemType e;
                e.x = now.x + di[i][0];
                e.y = now.y + di[i][1];
                e.step = now.step + 1;
                enqueue(e);
            }
        }
    }
    return -1;
}


int main() {
    int M, N, start[2], end[2];
    char maze[20][20];
    scanf("%d %d", &M, &N);
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            while((maze[i][j] = getchar()) == '\n');
            if(maze[i][j] == '@'){
                start[0] = i;
                start[1] = j;
            }else if(maze[i][j] == '*'){
                end[0] = i;
                end[1] = j;
            }
        }
    }
    printf("%d", bfs(maze, M, N, start, end));
    return 0;
}