/** @file log.c */
#include <stdlib.h>
#include <string.h>
#include "log.h"

/**
对log进行初始化，log的“构造函数”
 */

void log_init(log_t *l) {
    l->head = NULL;
}

/**
销毁一个log，释放所有内存空间，log的“析构函数”
 */

void node_destroy(node* n) {
    if(n->next != NULL){
        node_destroy(n->next);
    }
    free(n->cmd);
    free(n);
    return;
}
void log_destroy(log_t* l) {
    if(l->head != NULL){
        node_destroy(l->head);
        l->head = NULL;
    }
    return;
}

/**
向log中推入一个字符串，你可以将log视为一个由链表组成的栈
 */

void log_push(log_t* l, const char *item) {
    node* n = (node*)malloc(sizeof(node));
    n->cmd = (char*)malloc((strlen(item) + 1) * sizeof(char));
    strcpy(n->cmd, item);
    n->next = l->head;
    l->head = n;
}


/**
搜索log中是否含有对应前缀的字符串
 */

char *log_search(log_t* l, const char *prefix) {
    node* n = l->head;
    while(n != NULL){
        int i;
        for(i = 0;prefix[i] != '\0';i++){
            if(prefix[i] != n->cmd[i]){
                break;
            }
        }
        if(prefix[i] == '\0'){
            return n->cmd;
        }
        n = n->next;
    }
    return NULL;
}

