#include <stdio.h>
//邻接表
typedef struct arc{
    int number;
    struct arc *nextarc;
}Arc;
typedef struct linknode{
    int visit;
    struct arc *firstarc;
}LinkNode;

LinkNode *linklist[100010];

void addArc(int a, int b){
    Arc *newarc = (Arc*)malloc(sizeof(Arc));
    newarc->number = b;
    newarc->nextarc = linklist[a]->firstarc;
    linklist[a]->firstarc = newarc;
    newarc = (Arc*)malloc(sizeof(Arc));
    newarc->number = a;
    newarc->nextarc = linklist[b]->firstarc;
    linklist[b]->firstarc = newarc;
}

void initialize(int n){
    for(int i = 1;i <= n;i++){
        linklist[i] = (LinkNode*)malloc(sizeof(LinkNode));
        linklist[i]->visit = 0;
        linklist[i]->firstarc = NULL;
    }
}

//循环队列
typedef struct{
    LinkNode *child;
    int step;
}ElemType;

#define QueueLength 5010
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
//广搜
int bfs(LinkNode *linklist[], int start, int time) {
    ElemType now;
    now.child = linklist[start];
    now.step = 1;
    enqueue(now);
    while (front != rear) {
        dequeue(&now);
        Arc *ap = now.child->firstarc;
        while(ap != NULL){
            if(!linklist[ap->number]->visit){
                linklist[ap->number]->visit = 1;
                ElemType temp;
                temp.child = linklist[ap->number];
                temp.step = now.step + 1;
                enqueue(temp);
            }
            ap = ap->nextarc;
        }
    }
    return now.step + time;
}


int main() {
    int n, p, c, m, a, b;
    scanf("%d %d %d %d", &n, &p, &c, &m);
    initialize(n);
    for(int i = 0;i < p;i++){
        scanf("%d %d", &a, &b);
        addArc(a, b);
    }
    printf("%d", bfs(linklist, c, m));
    return 0;
}