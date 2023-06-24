#include <stdio.h>
#include <string.h>

// 函数用于将字符串按规则加密
void encryptMessage(char* message, char* encrypted_message) {
    int message_length = strlen(message);
    int encrypted_index = 0;

    for (int i = 0; i < message_length; i++) {
        // 判断当前字符是否是 'a'，且后续两个字符为 'b' 和 'c'
        if (message[i] == 'a' && i + 2 < message_length && message[i + 1] == 'b' && message[i + 2] == 'c') {
            // 将 "abc" 加密为 "123bcd"
            encrypted_message[encrypted_index++] = '1';
            encrypted_message[encrypted_index++] = '2';
            encrypted_message[encrypted_index++] = '3';
            encrypted_message[encrypted_index++] = 'b';
            encrypted_message[encrypted_index++] = 'c';
            encrypted_message[encrypted_index++] = 'd'; // 加入缺漏的 'd'
            i += 2; // 跳过已加密的字符
        } else {
            encrypted_message[encrypted_index++] = message[i];
        }
    }

    encrypted_message[encrypted_index] = '\0'; // 添加字符串结束符
}

int main() {
    char message1[501];
    char message2[501];

    fgets(message1, sizeof(message1), stdin);
    fgets(message2, sizeof(message2), stdin);

    // 移除 message1 和 message2 的换行符
    int length1 = strlen(message1);
    if (message1[length1 - 1] == '\n') {
        message1[length1 - 1] = '\0';
    }

    int length2 = strlen(message2);
    if (message2[length2 - 1] == '\n') {
        message2[length2 - 1] = '\0';
    }

    // 定义加密后的消息数组
    char encrypted_message1[1001];
    char encrypted_message2[1001];

    // 加密消息
    encryptMessage(message1, encrypted_message1);
    encryptMessage(message2, encrypted_message2);

    // 输出加密后的消息
    printf("%s\n", encrypted_message1);
    printf("%s\n", encrypted_message2);

    return 0;
}
