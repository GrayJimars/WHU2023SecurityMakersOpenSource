#include <stdio.h>
#include <string.h>

int main() {
    char a[20001];
    int c[20001];
    c[1] = 0; // 初始化c数组为0
    fgets(a, sizeof(a), stdin);
    int n = strlen(a);
    a[n - 1] = ' '; // 句末追加空格用于判断最后一个单词结束

    int m = 0, o = 0;
    int max = 0, least = 0, max_number = 0, least_number = 0;

    // 将单词字母数存放入数组c中
    for (int i = 0; i < n; i++) {
        if ((a[i] == ',' || a[i] == ' ') && (a[i + 1] != ',' && a[i + 1] != ' ')) {
            o = i + 1;
        }
        if ((a[i] != ',' && a[i] != ' ') && (a[i + 1] == ',' || a[i + 1] == ' ')) {
            c[i] = i - o + 1;
        }
    }

    // 找到最长、最短的单词的位置
    for (int i = 0; i < n; i++) {
        if (c[i] != 0) {
            max = c[i];
            least = c[i];
            max_number = i;
            least_number = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (c[i] != 0) {
            if (c[i] > max) {
                max = c[i];
                max_number = i;
            }
            if (c[i] < least) {
                least = c[i];
                least_number = i;
            }
        }
    }

    // 输出最长、最短的单词
    for (int i = max_number - max + 1; i <= max_number; i++) {
        printf("%c", a[i]);
    }
    printf("\n");

    for (int i = least_number - least + 1; i <= least_number; i++) {
        printf("%c", a[i]);
    }

    return 0;
}
