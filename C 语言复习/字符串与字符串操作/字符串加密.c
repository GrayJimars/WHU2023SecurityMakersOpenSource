#include <stdio.h>
#include <string.h>

void encryptMessage(char* message) {
    int message_length = strlen(message), encrypted_index = 0;
    char temp[501];
    for (int i = 0; i < message_length - 2; i++) {
        if (message[i] == 'a' && message[i + 1] == 'b' && message[i + 2] == 'c') {
            strcpy(temp, message + i + 3);
            strcpy(message + i, "123bcd");
            i += 5;
            message_length += 3;
            strcpy(message + i + 1, temp);
        }
    }
}

int main() {
    char message1[501], message2[501];
    scanf("%s%s", message1, message2);
    encryptMessage(message1);
    encryptMessage(message2);
    printf("%s\n%s\n", message1, message2);
    return 0;
}
