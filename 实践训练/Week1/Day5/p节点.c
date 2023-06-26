#include <stdio.h>
#define MAXV 1001

int degree[MAXV], t, adjgraph[MAXV][MAXV + 2];

void Initialize(int degree[], int adjgraph[MAXV][MAXV + 2], int n) {
    memset(degree, 0, MAXV * sizeof(int));
    memset(adjgraph, 0, MAXV * (MAXV + 2) * sizeof(int));
}

int main() {
    scanf("%d", &t);

    int n = MAXV, x, y;
    for (int i = 0; i < t; i++) {
        int pcount = 0;
        Initialize(degree, adjgraph, n);
        scanf("%d", &n);
        for (int j = 1; j < n; j++) {
            scanf("%d %d", &x, &y);
            degree[x]++;
            adjgraph[x][adjgraph[x][MAXV]++] = y;
            adjgraph[y][MAXV + 1] = x;
        }

        for (int j = 1; j <= n; j++) {
            if (degree[adjgraph[j][MAXV + 1]] > degree[j]) {
                continue;
            }
            int isp = 1;
            for (int k = 0; k < adjgraph[j][MAXV]; k++) {
                if (degree[adjgraph[j][k]] > degree[j]) {
                    isp = 0;
                    break;
                }
            }
            if (isp) {
                pcount++;
            }
        }
        printf("%d\n", pcount);
    }
    return 0;
}