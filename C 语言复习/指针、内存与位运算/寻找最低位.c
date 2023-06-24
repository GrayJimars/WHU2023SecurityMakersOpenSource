#include <stdio.h>

int getLowestBit(int num) {
    if (num == 0)
        return 0;
        
    int lowestBit = num & (-num); // 使用按位与操作符获取最低位

    int count = 0;
    while (lowestBit != 1) {
        lowestBit >>= 1; // 右移一位
        count++; // 统计右移的次数，即最低位的位置
    }

    return count;
}

int main() {
    int A;

    while (1) {
        scanf("%d", &A);

        if (A == 0)
            break;

        int lowestBit = getLowestBit(A);

        printf("%d\n", 1 << lowestBit);
    }

    return 0;
}
