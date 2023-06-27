#include <stdio.h>
#include <stdlib.h>
//循环队列
//队中的元素：空洞
typedef struct {
    long long x, y, z;
    int visit, step;
}Hole;
typedef Hole ElemType;
#define QueueLength 5010
typedef struct {
    ElemType queue[QueueLength];
    int front, rear;
}Queue;
//判断是否到达终点
int isEnd(ElemType now, long long h, long long r) {
    return now.z >= h - r;
}
//判断两个洞之间是否相通
int isAccessable(ElemType h1, ElemType h2, long long r) {
    return (h1.x - h2.x) * (h1.x - h2.x)
        + (h1.y - h2.y) * (h1.y - h2.y)
        + (h1.z - h2.z) * (h1.z - h2.z) <= 4 * r * r;
}
//广搜
int bfs(Queue* q, ElemType hole[], long long n, long long h, long long r) {
    ElemType now;//当前的洞
    while (q->front != q->rear) {
        q->front = (q->front + 1) % QueueLength;
        now = q->queue[q->front];//从队列取出一个到now
        if (isEnd(now, h, r)) {//如果满足终点条件
            return now.step;//返回这个洞的抵达步数
        }
        for (int i = 1; i <= n; i++) {
            if (!hole[i].visit && isAccessable(now, hole[i], r)) {
                hole[i].visit = 1;
                hole[i].step = now.step + 1;
                q->rear = (q->rear + 1) % QueueLength;
                q->queue[q->rear] = hole[i];//入队
            }
        }
    }
    return -1;
}
//获取洞的信息
void getHoles(Queue* q, ElemType hole[], long long n, long long r) {
    for (int i = 1; i <= n; i++) {
        Hole temp;
        scanf("%lld %lld %lld", &temp.x, &temp.y, &temp.z);
        temp.visit = 0;
        if (temp.z <= r) {//如果可以是起点
            temp.visit = 1;
            temp.step = 1;
            q->rear = (q->rear + 1) % QueueLength;
            q->queue[q->rear] = temp;//入队
        }
        hole[i] = temp;//编号为i
    }
}
int main() {
    long long T, n, h, r;
    scanf("%lld", &T);
    while (T--) {
        ElemType hole[5010];//定义洞数组
        Queue* q = (Queue*)malloc(sizeof(Queue));//创建队列
        q->front = q->rear = -1;
        scanf("%lld %lld %lld", &n, &h, &r);//接受n，h，r
        getHoles(q, hole, n, r);//开始获取所有洞的信息
        printf("%d\n", bfs(q, hole, n, h, r));//开始广搜
        free(q);//释放队列
    }
    return 0;
}