#include <stdio.h>
#include <stdbool.h>

bool isComposite(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return true;
    }

    return false;
}

bool isPalindrome(int num) {
    int reversedNum = 0;
    int originalNum = num;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return (originalNum == reversedNum);
}

int main() {
    int n;
    scanf("%d", &n);

    int count = 0;

    for (int i = 0; i < n; i++) {
        int queryType, num;
        scanf("%d %d", &queryType, &num);

        if (queryType == 1) {
            if (isComposite(num))
                count++;
        } else if (queryType == 2) {
            if (isPalindrome(num))
                count++;
        } else if (queryType == 3) {
            if (isComposite(num) && isPalindrome(num))
                count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
