#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//空洞
typedef struct {
    long long x;//坐标
    long long y;
    long long z;
}Hole;
Hole hole[1010];//空洞按编号储存
//邻接表
typedef struct arc {
    int number;//边另一头的空洞编号
    struct arc* nextarc;
}Arc;//相连关系
typedef struct linknode {
    int visit;
    int number;//空洞编号
    struct arc* firstarc;
}LinkNode;

LinkNode* linklist[1010];

//判断两个空洞是否相通
int isAccessable(Hole h1, Hole h2, long long r) {
    //圆心距离小于2r
    return sqrt((h1.x - h2.x) * (h1.x - h2.x)
        + (h1.y - h2.y) * (h1.y - h2.y)
        + (h1.z - h2.z) * (h1.z - h2.z)) <= 2 * r;
}
//添加无向边
void addArc(int a, int b) {
    //边a到b
    Arc* newarc = (Arc*)malloc(sizeof(Arc));
    newarc->number = b;
    newarc->nextarc = linklist[a]->firstarc;
    linklist[a]->firstarc = newarc;
    //边b到a
    newarc = (Arc*)malloc(sizeof(Arc));
    newarc->number = a;
    newarc->nextarc = linklist[b]->firstarc;
    linklist[b]->firstarc = newarc;
}
//分配内存
void initialize(long long n) {
    for (int i = 1; i <= n; i++) {
        linklist[i] = (LinkNode*)malloc(sizeof(LinkNode));
        linklist[i]->number = i;//赋初值，number代表邻接结点对应的洞编号
        linklist[i]->visit = 0;
        linklist[i]->firstarc = NULL;
    }
}
//释放内存
void FreeArc(Arc* arc) {
    if (arc == NULL) {
        return;//递归终点
    }
    FreeArc(arc->nextarc);//先递归
    free(arc);//后释放
}
void Free(long long n) {
    for (int i = 1; i <= n; i++) {
        FreeArc(linklist[i]->firstarc);//递归释放边元素
        free(linklist[i]);//释放这个邻接结点
    }
}
//循环队列
//队中的元素
typedef struct {
    LinkNode* hole;
    int step;
}ElemType;
#define QueueLength 5010
ElemType queue[5010];
int front = -1, rear = -1;
//入队
void enqueue(ElemType e) {
    rear = (rear + 1) % QueueLength;
    queue[rear] = e;
}
//出队
void dequeue(ElemType* e) {
    front = (front + 1) % QueueLength;
    *e = queue[front];
}
//广搜
//判断是否到达终点
int isend(ElemType now, long long h, long long r) {
    return hole[now.hole->number].z >= h - r;
}
//bfs
int bfs(long long h, long long r) {
    ElemType now;//当前的洞
    while (front != rear) {
        dequeue(&now);//从队列中出一个到now
        if (isend(now, h, r)) {//如果满足终点条件
            return now.step;//返回这个洞的抵达步数
        }
        Arc* ap = now.hole->firstarc;//根据邻接表
        while (ap != NULL) {
            if (!linklist[ap->number]->visit) {//将相互连通且没访问过的洞入队
                linklist[ap->number]->visit = 1;
                ElemType temp;
                temp.hole = linklist[ap->number];
                temp.step = now.step + 1;//抵达步数为当前洞的步数+1
                enqueue(temp);//入队
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
        scanf("%lld %lld %lld", &n, &h, &r);//接受n，h，r
        initialize(n);//根据n分配内存
        //开始获取所有洞的信息
        for (int i = 1; i <= n; i++) {
            Hole temp;
            scanf("%lld %lld %lld", &temp.x, &temp.y, &temp.z);
            if (temp.z <= r) {//如果可以是起点
                ElemType e;
                e.hole = linklist[i];
                e.step = 1;
                enqueue(e);//就入队
            }
            hole[i] = temp;
        }
        //获取洞信息结束
        //开始构造邻接表
        for (int i = 1; i <= n; i++) {//遍历1-n号洞
            for (int j = i + 1; j <= n; j++) {//遍历这个洞之后的洞
            //因为是无向关系，所以每任意两个洞之间只需要判断一次
                if (isAccessable(hole[i], hole[j], r)) {//如果连通
                    addArc(i, j);//加邻接关系（边）
                }
            }
        }
        printf("%d\n", bfs(h, r));//开始广搜
        front = rear;//重置队列
        Free(n);//释放内存
    }
    return 0;
}