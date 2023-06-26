#include<stdio.h>
#include<stdlib.h>

typedef struct arc{
    int number;
    struct arc *nextarc;
}Arc;
typedef struct linknode{
    int visit;
    struct arc *firstarc;
}LinkNode;

LinkNode *linklist[20010];

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

void dfs(int idx){
    if(linklist[idx]->visit){
        return;
    }
    linklist[idx]->visit = 1;
    Arc *ap = linklist[idx]->firstarc;
    while(ap != NULL){
        dfs(ap->number);
        ap = ap->nextarc;
    }
}

void initialize(int n){
    for(int i = 1;i <= n;i++){
        linklist[i] = (LinkNode*)malloc(sizeof(LinkNode));
        linklist[i]->visit = 0;
        linklist[i]->firstarc = NULL;
    }
}

int main(){
    int n, m, a, b, count = 0;
    scanf("%d %d", &n, &m);
    initialize(n);
    for(int i = 0;i < m;i++){
        scanf("%d %d", &a, &b);
        addArc(a, b);
    }
    for(int i = 1;i <= n;i++){
        if(linklist[i]->visit == 0){
            dfs(i);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}