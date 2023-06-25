#include <stdio.h>
int main() {
    char input[501], stack[501];
    fgets(input, sizeof(input), stdin);
    int top = -1, length = strlen(input);
    for(int i = 0;i < length;i++){
        if(input[i] == ' '){
            while(top > -1){
                putchar(stack[top--]);
            }
            putchar(' ');
        }else{
            stack[++top] = input[i];
        }
    }
    top--;
    while(top > -1){
        putchar(stack[top--]);
    }
    return 0;
}