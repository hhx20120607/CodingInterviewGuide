#include <stdio.h>
#include <malloc.h>

/**
 * 将单链表的每k个节点之间逆序
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
    int i = 1, j = n / k * k;
    node *p = NULL, *q = NULL;
    h = NULL, t = NULL;
    while (c && i <= j) {
        node *n = c->next;
        c->next = p;
        p = c;
        if (!q)
            q = c;
        if (i % k == 0) {
            if (!h) {
                h = p;
                t = q;
            } else {
                t->next = p;
                t = q;
            }
            p = NULL;
            q = NULL;
        }
        c = n;
        i++;
    }
    t->next = c;
    while (h) {
        node *n = h;
        printf("%d ", h->data);
        h = h->next;
        free(n);
    }
    return 0;
}
