#include <stdio.h>
#include <string.h>

void removeSuffix(char *word) {
    int length = strlen(word);
    
    if (length >= 2) {
        if (strcmp(word + length - 2, "er") == 0) {
            word[length - 2] = '\0';
        } else if (strcmp(word + length - 2, "ly") == 0) {
            word[length - 2] = '\0';
        }
    }
    
    if (length >= 3) {
        if (strcmp(word + length - 3, "ing") == 0) {
            word[length - 3] = '\0';
        }
    }
}

int main() {
    char word[100];
    
    scanf("%s", word);
    
    removeSuffix(word);
    
    printf("%s\n", word);
    
    return 0;
}
