#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;

int linkedListCycleLength(ListNode *head) {
    ListNode *slow_pointer = head, *fast_pointer = head;
    int hascircle = 0;
    while(slow_pointer->next != NULL && fast_pointer->next->next != NULL) {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        if(fast_pointer->next == NULL) {
            break;
        }
        if(fast_pointer == slow_pointer) {
            hascircle = 1;
            break;
        }
    }
    if(hascircle) {
        int count = 0;
        do {
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        count++;
        }while(slow_pointer != fast_pointer);
        return count;
    } else {
        return 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    int d;
    scanf("%d", &d);
    ListNode *Nth = head;
    while (d--) {
        Nth = Nth->next;
    }
    temp->next = Nth;
    temp = head;
    head = head->next;
    free(temp);
    printf("%d\n", linkedListCycleLength(head));
    return 0;
}
