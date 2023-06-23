#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;

int hasIntersection(ListNode *head1, ListNode *head2) {
    while(head1->next) {
        head1 = head1->next;
    }
    while(head2->next) {
        head2 = head2->next;
    }
    return head1 == head2;
}

ListNode* findIntersectionListNode(ListNode *head1, ListNode *head2) {
    if(!hasIntersection(head1, head2)) {
        return NULL;
    }
    ListNode *h1 = head1, *h2 = head2;
    while(h1 != NULL && h2 != NULL) {
        h1=h1->next;
        h2=h2->next;
    }
    int count = 0, head1_shorter;
    while(h1 != NULL) {
        h1=h1->next;
        count++;
        head1_shorter = 0;
    }
    while(h2 != NULL) {
        h2=h2->next;
        count++;
        head1_shorter = 1;
    }
    if(head1_shorter) {
        for(int i = 0;i < count;i++) {
            head2 = head2->next;
        }
    } else {
        for(int i = 0;i < count;i++) {
            head1 = head1->next;
        }
    }
    while(head1 != head2) {
        head1=head1->next;
        head2=head2->next;
    }
    return head1;
}
int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    ListNode *ans = NULL;
    for (int i = 0; i < n; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
        if (i == x) {
            ans = temp;
        }
    }
    temp = head;
    head = head->next;
    free(temp);
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->val = 0;
    head2->next = NULL;
    temp = head2;
    for (int i = 0; i < m; ++i) {
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = 0;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp->next = ans;
    temp = head2;
    head2 = head2->next;
    free(temp);
    temp = findIntersectionListNode(head, head2);
    if(temp == ans) {
        printf("Accept\n");
    } else {
        printf("Wrong answer\n");
    }
    return 0;
}
