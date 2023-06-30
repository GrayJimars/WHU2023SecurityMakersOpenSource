#include "state.h"
#include <string.h>
#define maxn 5000
#define maxm 30000
#define min(a,b) (((a)<(b))?(a):(b))
const int infinite = 0x3f3f3f3f;

typedef struct {//边列表
    int length, goal, next_edge, valid;
}edge;
edge edge_list[maxm];

int distance[maxn];//记录距离

//邻接表数组
int first_edge[maxn], edge_id = 0, start = 1, n, 
visit[maxn], pre_node[maxn], first_min, 
shortest_path[maxn], sptop = -1,
shortest_edge[maxn], setop = -1;

void insert(struct State *s, int from, int to, int di) {
    int length, valid;//长度 和 边的合法值
    if(to < 1 || to > n){//目标点不在范围内，合法值为0
        length = 0;
        valid = 0;
    }else{
        length = s->industry[to];
        valid = 1;
    }
    //计算二维坐标
    int x = (from - 1) / (2 * s->width - 1) * 2 + 
    (((from - 1) % (2 * s->width - 1)) >= s->width) , 

    y = (from - 1) % (2 * s->width - 1) - 
    s->width * (((from - 1) % (2 * s->width - 1)) >= s->width);

    //如果是本行的开头到上一行的结尾，合法值为0
    if(y == 0 && di == 1){
        valid = 0;
    }
    //如果是本行的结尾到下一行的开头，合法值为0
    else if((((x % 2) && y == s->width - 2) 
    || (!(x % 2) && y == s->width - 1)) 
    && di == 0){
        valid = 0;
    }
    else if(!(x % 2)){
        if(y == 0 
           && (di == 2 || di == 4)){
            valid = 0;
        }else if(y == s->width - 1 
                 && (di == 3 || di == 5)){
            valid = 0;
        }
    }
    //printf("length:%d to:%d valid:%d\n", length, to, valid);
    //头插法添加新的边
    edge new_edge = { length, to, first_edge[from], valid };
    edge_list[edge_id] = new_edge;
    first_edge[from] = edge_id++;
}
//禁用边
void disable(int edge_id) {
    edge_list[edge_id].valid = 0;
}
//启用边
void enable(int edge_id) {
    edge_list[edge_id].valid = 1;
}
//求单源最短路径
void dijkstra() {
    memset(distance, 0x3f, sizeof(distance));
    distance[start] = 0;
    for (int i = 1; i <= n; i++) {
        int min_distance = infinite;
        int closest_node;
        for (int j = 1; j <= n; j++) {
            if (!visit[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                closest_node = j;
            }
        }
        if (min_distance == infinite) {
            break;
        }
        visit[closest_node] = 1;
        for (int j = first_edge[closest_node]; j != -1; j = edge_list[j].next_edge) {
            if (edge_list[j].valid) {
                int v = edge_list[j].goal;
                if (distance[v] > distance[closest_node] + edge_list[j].length) {
                    distance[v] = distance[closest_node] + edge_list[j].length;
                    pre_node[v] = closest_node;
                }
            }
        }
    }
}
//取最短路径 经过的边
void getShortestedges(int node) {

    //获取最短路径经过的节点
    while (node != start) {
        shortest_path[++sptop] = node;
        node = pre_node[node];
    }
    shortest_path[++sptop] = node;

    //获取最短路径经过的边
    for (int i = sptop; i > 0; i--) {
        for (int j = first_edge[shortest_path[i]]; j != -1; j = edge_list[j].next_edge) {
            if (edge_list[j].goal == shortest_path[i - 1]) {
                shortest_edge[++setop] = j;
            }
        }
    }
}

//做做样子
void init_State(struct State *s) {
    s->width = 0;
    s->height = 0;
}

//用的数组所以不用删
void delete_State(struct State *s) {
    return;
}
//根据像素点颜色获取工业产值
int get_industrial_value(struct PXL* p){
    return 255 * 255 * 3 - p->red * p->red - p->green * p->green - p->blue * p->blue;
}
void parse(struct State *s, struct PNG *p) {
    int idx = 1;
    //计算国家的宽度和高度（相对于图片的宽度和高度而言）
    s->width = (p->width - 1) / 8;
    s->height = (p->height - 5) / 8;
    //读取工业产值信息，读图可知每8个像素点为每一个区域的中心
    for(int i = 0;i < s->height;i++){
        if(i % 2){
            for(int j = 0;j < s->width - 1;j++){
                int y = 6 + 8 * i, x = 8 + 8 * j;
                s->industry[idx++] = get_industrial_value(get_PXL(p, x, y));//求工业产值
            }
        }else{
            for(int j = 0;j < s->width;j++){
                int y = 6 + 8 * i, x = 4 + 8 * j;
                s->industry[idx++] = get_industrial_value(get_PXL(p, x, y));//求工业产值
            }
        }
    }
}
int solve1(struct State *s) {
    //初始化
    start=1;
    int width=s->width;
    int height=s->height;
    memset(first_edge, -1, sizeof(first_edge));
    memset(visit, 0, sizeof(visit));
    //每个节点六个方向对应的节点
    int di[6]= { 1, -1, -width, -width + 1, width - 1, width};
    //节点数量
    n = width * height-height / 2;
    //m=(width-1)*height-h/2+2*(height-1)*(width-1);

    //对于所有节点生成可走边，插入表中
    for (int i = 1; i <= n; i++) {
        //printf("node:%d\n", i);
        for(int j=0;j<6;j++) {
            //printf("edge:%d ", j);
            //在insert中考虑边界情况
            insert(s, i, i+di[j], j);
        }
    }
    //设置开始节点的前置节点为-1
    pre_node[start] = -1;
    dijkstra();
    first_min = distance[n];
    return first_min;
}
int solve2(struct State *s) {
    //找出最短路径经过的所有边
    getShortestedges(n);
    int second_min = infinite;

    for (int i = 0; i <= setop; i++) {
        memset(visit, 0, sizeof(visit));
        //每次禁用一条边
        disable(shortest_edge[i]);
        dijkstra();
        if(distance[n] > -1 && distance[n] > first_min){
            second_min = min(second_min, distance[n]);
        }
        //恢复边
        enable(shortest_edge[i]);
    }
    return second_min;
}