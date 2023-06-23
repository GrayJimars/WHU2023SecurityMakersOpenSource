#include <stdio.h>

int main() {
    char input[12];
    scanf("%s", input);
    int isnegative = input[0] == '-', startoutput = 0;
    
    if(isnegative) {
        putchar('-');
    }
    
    int i = strlen(input) - 1;
    for(;i > 0;i--) {
        if(startoutput == 1 || input[i] != '0') {
            putchar(input[i]);
            startoutput = 1;
        }
    }
    
    if(!isnegative) {
        putchar(input[0]);
    }
    
    return 0;
}