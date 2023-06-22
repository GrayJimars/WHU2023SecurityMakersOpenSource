#include<stdio.h>
int x, g, c[1000];
int main() {
    scanf("%d", &x);
    g = 0;
    while (x) {
        c[g++] = x % 8;
        x /= 8;
    }
    for (int i = g - 1; i >= 0; i--) {
        printf("%d", c[i]);
    }
    return 0;
}
