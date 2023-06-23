#include <stdio.h>

void Sort(int numbers[], int n, int reverse) {
    for(int i = 0;i < n;i++) {
        int m = i, temp;
        for(int j = i;j < n;j++) {
            if(reverse && numbers[m] < numbers[j]) {
                m = j;
            } else if(!reverse && numbers[m] > numbers[j]) {
                m = j;
            }
        }
        temp = numbers[i];
        numbers[i] = numbers[m];
        numbers[m] = temp;
    }
}

void Work(int numbers[]) {
    int oddstack[10], evenstack[10], oddtop = -1, eventop = -1;
    for (int i = 0;i < 10;i++) {
        if(numbers[i] % 2) {
            oddstack[++oddtop] = numbers[i];
        } else {
            evenstack[++eventop] = numbers[i];
        }
    }
    Sort(evenstack, eventop + 1, 1);
    Sort(oddstack, oddtop + 1, 0);
    while(oddtop > -1) {
        printf("%d ", oddstack[oddtop--]);
    }
    while(eventop > -1) {
        printf("%d ", evenstack[eventop--]);
    }
}

int main() {
    int numbers[10];
    for(int i = 0;i < 10;i++) {
        scanf("%d", numbers + i);
    }
    
    Work(numbers);
    return 0;
}