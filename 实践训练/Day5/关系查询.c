#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char name[50];
    int index;
} Mapping;

bool relation[MAX][MAX];

int main() {
    int n;
    scanf("%d", &n);

    int eid = 0;
    Mapping m[MAX];
    memset(relation, false, sizeof(relation));

    while (n--) {
        char s1[50], s2[50];
        scanf("%s %s", s1, s2);

        int index1 = -1, index2 = -1;
        for (int i = 0; i < eid; i++) {
            if (strcmp(s1, m[i].name) == 0) {
                index1 = i;
            }
            if (strcmp(s2, m[i].name) == 0) {
                index2 = i;
            }
        }

        if (index1 == -1 && index2 == -1) {
            strcpy(m[eid].name, s1);
            m[eid].index = eid;
            index1 = eid++;

            strcpy(m[eid].name, s2);
            m[eid].index = eid;
            index2 = eid++;
        } else if (index1 == -1) {
            strcpy(m[eid].name, s1);
            m[eid].index = eid;
            index1 = eid++;
        } else if (index2 == -1) {
            strcpy(m[eid].name, s2);
            m[eid].index = eid;
            index2 = eid++;
        }

        relation[index1][index2] = true;
        relation[index2][index1] = true;
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        char s1[50], s2[50];
        scanf("%s %s", s1, s2);

        int index1 = -1, index2 = -1;
        for (int i = 0; i < eid; i++) {
            if (strcmp(s1, m[i].name) == 0) {
                index1 = i;
            }
            if (strcmp(s2, m[i].name) == 0) {
                index2 = i;
            }
        }

        if (index1 == -1 || index2 == -1) {
            printf("No\n");
        } else if (relation[index1][index2] && relation[index2][index1]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
