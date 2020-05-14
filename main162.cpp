#include <stdio.h>
#include <malloc.h>

/**
 * 向有序的环形单链表中插入新节点
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
    t->next = h;
    int m;
    scanf("%d", &m);
    node *p = h;
    node *q = t;
    node *c = (node *) malloc(sizeof(node));
    c->next = NULL;
    c->data = m;
    bool find = false;
    while (true) {
        if (p->data > c->data) {
            find = true;
            break;
        }
        q = p;
        p = p->next;
        if (p == h)
            break;
    }
    q->next = c;
    c->next = p;
    if (p == h) {
        if (find) {
            h = c;
        } else {
            t = c;
        }
    }
    p = h;
    while (true) {
        printf("%d ", p->data);
        node *t = p;
        p = p->next;
        free(t);
        if (p == h)
            break;
    }

}