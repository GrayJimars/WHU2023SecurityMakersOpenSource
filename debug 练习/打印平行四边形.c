#include<stdio.h>

int main() {
    char c;
    int n, m, blank;
    scanf("%c%d%d", & c, & n, & m);
    blank = n;
    for (int i = 1; i <= n; i++) {
        blank--;
        for (int j = 1; j <= blank; j++)
            printf("  ");
        for (int j = 1; j <= m; j++)
            printf("%c ", c);
        printf("\n");
    }
    return 0;
}
