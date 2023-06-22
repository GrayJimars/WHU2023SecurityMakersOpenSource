#include <stdio.h>
#define maxn 1010
char ch[maxn][maxn];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%c", ch[i - j][j]);
        }
        puts("");
    }
    return 0;
}
