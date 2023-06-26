#include <stdio.h>

#define INCREASE 1
#define DECREASE -1

#define QueueLength 10000
int queue[QueueLength][2], visit[10000] = { 0 };
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

int INorDEcrease(int password, int position, int flag) {
    int stack[12], top = -1;
    while (password) {
        stack[++top] = password % 10;
        password /= 10;
    }
    stack[position - 1] += flag;
    if (stack[position - 1] == 10) {
        stack[position - 1] = 1;
    }
    else if (stack[position - 1] == 0) {
        stack[position - 1] = 9;
    }
    while (top > -1) {
        password *= 10;
        password += stack[top--];
    }
    return password;
}

int Swap(int password, int pos) {
    int stack[12], top = -1;
    while (password) {
        stack[++top] = password % 10;
        password /= 10;
    }
    int temp = stack[pos - 1];
    stack[pos - 1] = stack[pos];
    stack[pos] = temp;
    while (top > -1) {
        password *= 10;
        password += stack[top--];
    }
    return password;
}

int bfs(int start, int end) {
    enqueue(start, 0);
    int password, count;
    while (front != rear) {
        dequeue(&password, &count);
        if (password == end) {
            return count;
        }
        for (int i = 1; i <= 4; i++) {
            if(!visit[INorDEcrease(password, i, INCREASE)]){
                visit[INorDEcrease(password, i, INCREASE)] = 1;
                enqueue(INorDEcrease(password, i, INCREASE), count + 1);
            }
            if(!visit[INorDEcrease(password, i, DECREASE)]){
                visit[INorDEcrease(password, i, DECREASE)] = 1;
                enqueue(INorDEcrease(password, i, DECREASE), count + 1);
            }
        }
        for (int i = 1; i <= 3; i++) {
            if(!visit[Swap(password, i)]){
                visit[Swap(password, i)] = 1;
                enqueue(Swap(password, i), count + 1);
            }
        }
    }
    return -1;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d", bfs(A, B));
    return 0;
}