#include <stdio.h>

int feb(int n, int *a, int *b, int *p){
    if( n == 1 || n == 2){
        return 1;
    }
    return (*a * feb(n - 1, a, b, p)) % *p + (*b * feb(n - 2, a, b, p)) % *p;
}

int main(){
    int n, a, b, p;
    scanf("%d %d %d %d", &n, &a, &b, &p);
    printf("%ld", feb(n, &a, &b, &p) % p);
    return 0;
}