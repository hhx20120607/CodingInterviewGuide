#include <stdio.h>
#include <malloc.h>

/**
 * 合并两个有序的单链表
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
    node *p = NULL, *q = NULL;
    for (int i = 0; i < m; i++) {
        node *n = (node *) malloc(sizeof(node));
        int d;
        scanf("%d", &d);
        n->next = NULL;
        n->data = d;
        if (i == 0) {
            p = n;
            q = n;
        } else {
            q->next = n;
            q = n;
        }
    }
    node *u = NULL, *v = NULL;
    while (h && p) {
        node *c = h->data < p->data ? h : p;
        if (!u) {
            u = c;
            v = c;
        } else {
            v->next = c;
            v = c;
        }
        if (c == h) {
            h = h->next;
        } else {
            p = p->next;
        }
    }
    if (h) {
        if (!u) {
            u = h;
        } else {
            v->next = h;
            v = t;
        }
    }
    if (p) {
        if (!u) {
            u = p;
        } else {
            v->next = p;
            v = q;
        }
    }
    while (u) {
        printf("%d ", u->data);
        node *c = u;
        u = u->next;
        free(c);
    }
}