#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//空洞
typedef struct {
    long long x;
    long long y;
    long long z;
}Hole;
Hole hole[1010];
//邻接表
typedef struct arc {
    int number;
    struct arc* nextarc;
}Arc;
typedef struct linknode {
    int visit;
    int number;
    struct arc* firstarc;
}LinkNode;

LinkNode* linklist[1010];

int isAccessable(Hole h1, Hole h2, long long r) {
    return sqrt((h1.x - h2.x) * (h1.x - h2.x)
        + (h1.y - h2.y) * (h1.y - h2.y)
        + (h1.z - h2.z) * (h1.z - h2.z)) <= 2 * r;
}

void addArc(int a, int b) {
    Arc* newarc = (Arc*)malloc(sizeof(Arc));
    newarc->number = b;
    newarc->nextarc = linklist[a]->firstarc;
    linklist[a]->firstarc = newarc;
    newarc = (Arc*)malloc(sizeof(Arc));
    newarc->number = a;
    newarc->nextarc = linklist[b]->firstarc;
    linklist[b]->firstarc = newarc;
}

void initialize(long long n) {
    for (int i = 1; i <= n; i++) {
        linklist[i] = (LinkNode*)malloc(sizeof(LinkNode));
        linklist[i]->number = i;
        linklist[i]->visit = 0;
        linklist[i]->firstarc = NULL;
    }
}

void FreeArc(Arc* arc) {
    if (arc == NULL) {
        return;
    }
    FreeArc(arc->nextarc);
    free(arc);
}

void Free(long long n) {
    for (int i = 1; i <= n; i++) {
        FreeArc(linklist[i]->firstarc);
        free(linklist[i]);
    }
}

//循环队列
typedef struct {
    LinkNode* hole;
    int step;
}ElemType;

#define QueueLength 5010
ElemType queue[5010];
int front = -1, rear = -1;
void enqueue(ElemType e) {
    rear = (rear + 1) % QueueLength;
    queue[rear] = e;
}
void dequeue(ElemType* e) {
    front = (front + 1) % QueueLength;
    *e = queue[front];
}
//广搜
int isend(ElemType now, long long h, long long r) {
    return hole[now.hole->number].z >= h - r;
}

int bfs(long long h, long long r) {
    ElemType now;
    while (front != rear) {
        dequeue(&now);
        if (isend(now, h, r)) {
            return now.step;
        }
        Arc* ap = now.hole->firstarc;
        while (ap != NULL) {
            if (!linklist[ap->number]->visit) {
                linklist[ap->number]->visit = 1;
                ElemType temp;
                temp.hole = linklist[ap->number];
                temp.step = now.step + 1;
                enqueue(temp);
            }
            ap = ap->nextarc;
        }
    }
    return -1;
}

int main() {
    long long T, n, h, r;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld %lld %lld", &n, &h, &r);
        initialize(n);
        for (int i = 1; i <= n; i++) {
            Hole temp;
            scanf("%lld %lld %lld", &temp.x, &temp.y, &temp.z);
            if (temp.z <= r) {
                ElemType e;
                e.hole = linklist[i];
                e.step = 1;
                enqueue(e);
            }
            hole[i] = temp;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (isAccessable(hole[i], hole[j], r)) {
                    addArc(i, j);
                }
            }
        }
        printf("%d\n", bfs(h, r));
        front = rear;
        Free(n);
    }
    return 0;
}