#include<stdio.h>
int n, p[20], visit[20] = { 0 }, ok = 0, sum = 0, arc[3] = { 0 };
void dfs(int arc_number, int p_number) {
    if (ok) {
        return;
    }
    if (arc_number > 2) {
        ok = 1;
        return;
    }
    for (int i = p_number; i < n;i++) {
        if (!visit[i]) {
            visit[i] = 1;
            arc[arc_number] += p[i];
            if (arc[arc_number] == sum) {
                dfs(arc_number + 1, 0);
            }
            else if(arc[arc_number] < sum){
                dfs(arc_number, i + 1);
            }
            arc[arc_number] -= p[i];
            visit[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        sum += p[i];
    }
    if (sum % 4) {
        printf("No");
        return 0;
    }
    sum /= 4;
    for (int i = 0; i < n; i++) {
        if (p[i] > sum) {
            printf("No");
            return 0;
        }
    }
    dfs(0, 0);
    printf("%s", ok ? "Yes" : "No");
    return 0;
}