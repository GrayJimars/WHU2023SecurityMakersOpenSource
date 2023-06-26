#include <stdio.h>

#define QueueLength 5010
int queue[210][2], visit[210] = { 0 }, K[210];
int front = -1, rear = -1;
void enqueue(int e, int count) {
    rear = (rear + 1) % QueueLength;
    queue[rear][0] = e;
    queue[rear][1] = count;
}
void dequeue(int* e, int* count) {
    front = (front + 1) % QueueLength;
    *e = queue[front][0];
    *count = queue[front][1];
}

int in(int current_position, int N) {
    return current_position >= 0 && current_position <= N && !visit[current_position];
}

int bfs(int start, int end, int N) {
    enqueue(start, 0);
    int current_position, count;
    while (front != rear) {
        dequeue(&current_position, &count);
        if (current_position == end) {
            return count;
        }
        visit[current_position] = 1;
        if (in(current_position + K[current_position], N)) {
            enqueue(current_position + K[current_position], count + 1);
        }
        if (in(current_position - K[current_position], N)) {
            enqueue(current_position - K[current_position], count + 1);
        }
    }
    return -1;
}

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    for(int i = 1;i <= N;i++){
        scanf("%d", &K[i]);
    }
    printf("%d", bfs(A, B, N));
    return 0;
}