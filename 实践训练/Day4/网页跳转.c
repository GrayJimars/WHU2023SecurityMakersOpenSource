#include<stdio.h>

#define VISIT 0
#define BACK -1
#define FORWARD 1

char stack[100010][100];
int top = -1, length;

int Visit(char website[]) {
    if(top < 100010) {
        strcpy(stack[++top], website);
        length = top;
        puts(stack[top]);
        return 1;
    } else {
        return 0;
    }
}

void Back() {
    if(top > 0 && top != -1) {
        puts(stack[--top]);
    } else {
        puts("Ignore");
    }
}

void Forward() {
    if(top < length && top != -1) {
        puts(stack[++top]);
    } else {
        puts("Ignore");
    }
}

int check(char input[]) {
    if(strcmp(input, "VISIT") == 0) {
        return VISIT;
    } else if(strcmp(input, "BACK") == 0) {
        return BACK;
    } else {
        return FORWARD;
    }
}

int main() {
    int n;
    char input[120];
    scanf("%d", &n);
    
    for (int i = 0;i < n;i++) {
        scanf("%s", input);
        switch(check(input)) {
            case VISIT: {
                scanf("%s", input);
                Visit(input);
                break;
            }
            case BACK: {
                Back();
                break;
            }
            case FORWARD: {
                Forward();
                break;
            }
        }
    }
    return 0;
}