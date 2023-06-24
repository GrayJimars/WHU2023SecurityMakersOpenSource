#include <stdio.h>
#include <stdbool.h>

void removeExtraSpaces(char *sentence) {
    int i, j;
    bool spaceFlag = false;
    i = 0;
    j = 0;
    
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ') {
            if (!spaceFlag) {
                sentence[j] = sentence[i];
                j++;
            }
            spaceFlag = true;
        } else {
            sentence[j] = sentence[i];
            j++;
            spaceFlag = false;
        }
        
        i++;
    }
    
    sentence[j] = '\0';
}

int main() {
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);
    
    removeExtraSpaces(sentence);
    
    printf("%s\n", sentence);
    
    return 0;
}
