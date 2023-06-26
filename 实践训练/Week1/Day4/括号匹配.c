#include <stdio.h>

char stack[50010];
int top = 0;

void Push(char e) {
    stack[top++] = e;
}

char Pop() {
    return stack[--top];
}

int main() {
    char input[50010];
    int success_position[25010], position_top = 0, success_parent[50010] = { 0 }, success_count = 0;
    
    scanf("%s", input);
    
    for(int i = 0;input[i] != '\0';i++) {
        switch(input[i]) {
            case '(': {
                Push('(');
                success_position[position_top++] = i + 1;
                break;
            }
            case ')': {
                if(top == 0) {
                    printf("No\n");
                    return 0;
                } else {
                    Pop();
                    success_parent[success_position[--position_top]] = i + 1;
                    success_count++;
                }
                break;
            }
        }
    }
    
    if(top > 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
        for(int i = 0;i < 2 * success_count - 1;i++) {
            if(success_parent[i]){
                printf("%d %d\n", i, success_parent[i]);
            }
        }
    }
    
    return 0;
}