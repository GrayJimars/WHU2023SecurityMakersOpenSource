#include <stdio.h>

#define QueueLength 5010
int queue[5010][2];
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

int in(int visit[], int current_position, int n) {
    return current_position >= 0 && current_position <= n && !visit[current_position];
}

int bfs(int visit[], int start, int end, int n) {
    enqueue(start, 0);
    int current_position, count;
    while (front != rear) {
        dequeue(&current_position, &count);
        if (current_position == end) {
            return count;
        }
        visit[current_position] = 1;
        if (in(visit, current_position + 1, n)) {
            enqueue(current_position + 1, count + 1);
        }
        if (in(visit, current_position - 1, n)) {
            enqueue(current_position - 1, count + 1);
        }
        if (in(visit, current_position << 1, n)) {
            enqueue(current_position << 1, count + 1);
        }
    }
    return -1;
}


int main() {
    int n, A, B, visit[5010] = { 0 };
    scanf("%d %d %d", &n, &A, &B);
    printf("%d", bfs(visit, A, B, n));
    return 0;
}