#include <stdio.h>
#include <malloc.h>

/**
 * 在单链表中删除指定值的节点
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
    int k;
    scanf("%d", &k);
    node *c = h;
    h = NULL;
    t = NULL;
    while (c) {
        if (c->data != k) {
            if (!h) {
                h = c;
                t = c;
            } else {
                t->next = c;
                t = c;
            }
            c = c->next;
        } else {
            node *n = c->next;
            free(c);
            c = n;
        }
    }
    t->next = NULL;
    while (h) {
        printf("%d ", h->data);
        node *n = h->next;
        free(h);
        h = n;
    }
    return 0;
}
