#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT_IS_BIGGER 1
#define RIGHT_IS_BIGGER -1


int n, mark[21];
char students[21][21];

void Swap(int x, int y) {
    int temp_mark;
    char temp_name[21];

    temp_mark = mark[x];
    mark[x] = mark[y];
    mark[y] = temp_mark;

    strcpy(temp_name, students[x]);
    strcpy(students[x], students[y]);
    strcpy(students[y], temp_name);
}

int Compare(int left, int right) {
    if (mark[left] != mark[right]) {
        return mark[left] > mark[right] ? LEFT_IS_BIGGER : RIGHT_IS_BIGGER;
    }
    else {
        int lenl = strlen(students[left]), lenr = strlen(students[right]);
        for (int i = 0;i < lenl && i < lenr;i++) {
            if(students[left][i] > students[right][i]) {
                return -1;
            } else if(students[left][i] < students[right][i]) {
                return 1;
            }
        }
    }
}

void Bubble_Sort(int x) {
    for (int i = 0;i < x;i++) {
        int max = i;
        for (int j = i + 1;j < x;j++) {
            if (Compare(max, j) == RIGHT_IS_BIGGER) {
                max = j;
            }
        } 
        Swap(max, i);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d\n", students[i], &mark[i]);
    }
    
    Bubble_Sort(n);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i], mark[i]);
    }
    return 0;
}