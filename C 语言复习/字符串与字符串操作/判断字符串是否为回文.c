#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 函数用于判断字符串是否为回文
bool isPalindrome(char* str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {
    char str[501];
    fgets(str, sizeof(str), stdin);

    int length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0'; // 移除末尾的换行符
    }

    if (isPalindrome(str)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
