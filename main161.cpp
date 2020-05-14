#include <stdio.h>
#include <malloc.h>

/**
 * 一种怪异的节点删除方式
 */

typedef struct node {
    struct node *next;
    int data;
} node;


int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    node *h = NULL, *t = NULL;
    for (int i = 0; i < n; i++) {
        node *n = (node *) malloc(sizeof(node));
        int d;
        scanf("%d", &d);
        n->next = NULL;
        n->data = d;
        if (i == 0) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
    }
    int m;
    scanf("%d", &m);
    node *p = h;
    int i = 1;
    while (p) {
        if (i == m)
            break;
        p = p->next;
        i++;
    }
    p->data = p->next->data;
    p->next = p->next->next;
    while (h) {
        printf("%d ", h->data);
        node *n = h->next;
        free(h);
        h = n;
    }
}