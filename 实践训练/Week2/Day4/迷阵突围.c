#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 210
#define maxm 10010
#define min(a,b) (((a)<(b))?(a):(b))
const int infinite = 0x3f3f3f3f;

typedef struct {
    double length;
    int goal, next_edge, valid;
}edge;
edge edge_list[maxm * 2];

double distance[maxn];
int first_edge[maxn], edge_id = 0, start = 1, n, m, 
visit[maxn], pre_node[maxn], node[maxn][2],
shortest_path[maxn], sptop = -1,
shortest_edge[maxn], setop = -1;

void insert(int from, int to, double length) {
    edge new_edge = { length, to, first_edge[from], 1 };
    edge_list[edge_id] = new_edge;
    first_edge[from] = edge_id++;
}
void insert2(int from, int to, double length) {
    insert(from, to, length);
    insert(to, from, length);
}
void disable(int edge_id) {
    edge_list[edge_id].valid = 0;
}
void enable(int edge_id) {
    edge_list[edge_id].valid = 1;
}
void dijkstra() {
    for (int i = 1; i <= n; i++) {
        distance[i] = -2;
    }
    distance[start] = 0;
    for (int i = 1; i <= n; i++) {
        int min_distance = infinite;
        int closest_node;
        for (int j = 1; j <= n; j++) {
            if (!visit[j] && distance[j] < min_distance && distance[j] > -1) {
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
                if (distance[v] < -1 || distance[v] > distance[closest_node] + edge_list[j].length) {
                    distance[v] = distance[closest_node] + edge_list[j].length;
                    pre_node[v] = closest_node;
                }
            }
        }
    }
}
void getShortestedges(int node) {
    while (node != start) {
        shortest_path[++sptop] = node;
        node = pre_node[node];
    }
    shortest_path[++sptop] = node;
    for (int i = sptop; i > 0; i--) {
        for (int j = first_edge[shortest_path[i]]; j != -1; j = edge_list[j].next_edge) {
            if (edge_list[j].goal == shortest_path[i - 1]) {
                shortest_edge[++setop] = j;
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    memset(first_edge, -1, sizeof(first_edge));
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &node[i][0], &node[i][1]);
    }
    for (int i = 1; i <= m; i++) {
        int from, to;
        double length;
        scanf("%d%d", &from, &to);
        length = sqrt(pow(node[from][0] - node[to][0], 2) 
            + pow(node[from][1] - node[to][1], 2));
        insert2(from, to, length);
    }
    pre_node[start] = -1;
    dijkstra();
    getShortestedges(n);
    double second_min = infinite;
    for (int i = 0; i <= setop; i++) {
        memset(visit, 0, sizeof(visit));
        disable(shortest_edge[i]);
        dijkstra();
        if(distance[n] > -1){
            second_min = min(second_min, distance[n]);
        }
        enable(shortest_edge[i]);
    }
    printf("%.2lf", second_min);
    return 0;
}