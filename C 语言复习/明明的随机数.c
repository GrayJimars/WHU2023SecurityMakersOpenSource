#include <stdio.h>

int main() {
    int N, array[1001] = { 0 }, number, stack[1001], count = 0;
    scanf("%d", &N);
    for (int i = 0;i < N;i++) {
        scanf("%d", &number);
        array[number] = 1;
    }
    
    for (int i = 1;i < 1001;i++) {
        if(array[i] == 1) {
            stack[count++] = i;
        }
    }
    printf("%d\n", count);
    for (int i = 0;i < count;i++) {
        printf("%d ", stack[i]);
    }
    
    return 0;
}