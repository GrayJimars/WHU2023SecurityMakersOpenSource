#include <stdio.h>
#include <string.h>
#define maxn 1010
#define maxm 10010
#define min(a,b) (((a)<(b))?(a):(b))
const int infinite = 0x3f3f3f3f;

typedef struct{
    int goal, length, next_edge;
}edge;
edge edge_list[maxm * 2];

int first_edge[maxn], edge_id = 0, start = 1, n, m, distance[maxn], visit[maxn];

void insert(int from, int to, int length) {
    edge new_edge = { to, length, first_edge[from] };
    edge_list[edge_id] = new_edge;
    first_edge[from] = edge_id++;
}
void insert2(int from, int to, int length) {
    insert(from, to, length);
    insert(to, from, length);
}

int main() {
    scanf("%d%d", &n, &m);
    memset(first_edge, -1, sizeof(first_edge));
    for (int i = 0; i < m; i++) {
        int from, to, length;
        scanf("%d%d%d", &from, &to, &length);
        insert2(from, to, length);
    }
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
            int v = edge_list[j].goal;
            distance[v] = min(distance[v], distance[closest_node] + edge_list[j].length);
        }
    }
    printf("%d ", distance[n]);
    return 0;
}