#include <stdio.h>
#include <stdlib.h>

//单链表节点
typedef struct LNode {	
	int data;
	struct LNode* next;
}LinkNode;

//初始化单链表
void Lists_Initialize(LinkNode* linklist_heads[], int n) 
{
    for(int i = 0;i < n;i++) {
        linklist_heads[i] = (LinkNode*)malloc(sizeof(LinkNode));
        linklist_heads[i]->next = NULL;
    }
}

void Insert(LinkNode* linklist_heads[], int x, int y) {
    LinkNode* new_node = (LinkNode*)malloc(sizeof(LinkNode));
    new_node->data = y;
    new_node->next = linklist_heads[x]->next;
    linklist_heads[x]->next = new_node;
}

void Display(LinkNode* linklist_head) {
    if(linklist_head == NULL) {
        return;
    }
    Display(linklist_head->next);
    printf("%d ", linklist_head->data);
}

int main() {
    LinkNode* linklist_heads[10010];
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    Lists_Initialize(linklist_heads, n);
    
    for(int i = 0;i < m;i++) {
        scanf("%d %d", &x, &y);
        Insert(linklist_heads, x - 1, y);
    }
    
    for(int i = 0;i < n;i++) {
        Display(linklist_heads[i]->next);
        puts("");
    }
    
    return 0;
}