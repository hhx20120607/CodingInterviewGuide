#include <stdio.h>
#include <malloc.h>

/**
 * 环形单链表的约瑟夫问题
 */

typedef struct node {
    struct node *next;
    int data;
} node;

int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    node *h = NULL, *t = NULL;
    for (int i = 1; i <= n; i++) {
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = i;
        if (i == 1) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
    }
    if (t)
        t->next = h;
    node *p = h;
    int i = 1;
    while (p->next != p) {
        if (i % m == m - 1) {
            p->next = p->next->next;
            i++;
        }
        p = p->next;
        i++;
    }
    printf("%d", p->data);
    return 0;
}