#include<stdio.h>
#include<string.h>
#define maxn 100010
char s[maxn];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len - 2; i++) {
        int x;
        if (s[i] - 'j' >= 0) {
            x = s[i]-'j';
        } else {
            x = 26 - (int)('j' - s[i]);
        }
        char y = 'a' + ((int)('s' - 'a') + x) % 26;
        char z = 'a' + ((int)('k' - 'a') + x) % 26;
        if (s[i + 1] == y && s[i + 2] == z) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
