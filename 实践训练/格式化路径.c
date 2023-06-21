#include<stdio.h>

void Back(char output_string[], 
          int *top, 
          int *valueerror, 
          int *beginwithslash, 
          int *toppointslash) {
    if(*top == -1 
       || (*top == 0 
           && output_string[*top] == '/')) {
        *valueerror = 1;
        return;
    }
    if(output_string[*top] == '/') {
        (*top)--;
    }
    while(output_string[*top] != '/' && *top != -1) {
        (*top)--;
    }
    if(output_string[*top] == '/' && top != 0 && !*beginwithslash) {
        (*top)--;
        *toppointslash = 0;
    } else {
        *toppointslash = 1;
    }
}

int BeginWithSlash(char input_string[]) {
     if(input_string[0] == '\\' 
        || input_string[0] == '/') {
                return 1;
     } else {
         return 0;
     }
}

int GetOutputString(char input_string[], char output_string[]) {
    int beginwithslash = BeginWithSlash(input_string);
    int valueerror = 0, findonepoint = 0, toppointslash = 0, top = -1, i;
    
    for(i = 0;input_string[i] != '\0';i++) {
        switch(input_string[i]) {
            case '\\':case '/': {
                if((!toppointslash && top != -1) 
                   || (beginwithslash && top == -1)) {
                    output_string[++top] = '/';
                    toppointslash = 1;
                }
                findonepoint = 0;
                break;
            }
            case '.': {
                if(findonepoint) {
                    Back(output_string, 
                         &top, 
                         &valueerror, 
                         &beginwithslash, 
                         &toppointslash);
                    if(valueerror) {
                        return 1;
                    }
                    findonepoint = 0;
                } else {
                    findonepoint = 1;
                }
                break;
            }
            default: {
                output_string[++top] = input_string[i];
                toppointslash = 0;
                findonepoint = 0;
                break;
            }
        }
    }
    
    if(toppointslash && top != 0 && top != -1) {
        output_string[top] = '\0';
    } else {
        output_string[++top] = '\0';
    }
    
    return 0;
}

int main() {
    char input_string[110], output_string[110];
    
    while(scanf("%s", input_string) != EOF) {
        if(GetOutputString(input_string, output_string)) {
            printf("Value Error\n");
        } else {
            printf("%s\n", output_string);
        }
    }
    return 0;
}