#include <stdio.h>
#include <malloc.h>

/**
 * 按照左右半区的方式重新组合单链表
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
    int k = n / 2 + 1;
    int i = 1;
    node *q = NULL;
    node *p = h;
    while (p) {
        if (i == k)
            break;
        i++;
        q = p;
        p = p->next;
    }
    if (q)
        q->next = NULL;
    q = h;
    h = NULL;
    t = NULL;
    i = 1;
    while (q && p) {
        node *c = i % 2 == 1 ? q : p;
        if (!h) {
            h = c;
            t = c;
        } else {
            t->next = c;
            t = c;
        }
        if (i % 2 == 1) {
            q = q->next;
        } else {
            p = p->next;
        }
        i++;
    }
    if (p) {
        node *c = p;
        if (!h) {
            h = c;
            t = c;
        } else {
            t->next = c;
            t = c;
        }
        p = p->next;
    }
    while (h) {
        printf("%d ", h->data);
        node *c = h;
        h = h->next;
        free(c);
    }
}
