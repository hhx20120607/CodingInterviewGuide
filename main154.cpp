#include <stdio.h>
#include <malloc.h>

/**
 * 两个单链表生成相加链表
 */

typedef struct node {
    struct node *next;
    int data;
} node;

node *reverse(node *h) {
    node *t = NULL;
    while (h) {
        node *n = h->next;
        h->next = t;
        t = h;
        h = n;
    }
    return t;
}

node *add(node *h1, node *h2) {
    int c = 0;
    node *h = NULL, *t = NULL;
    while (h1 && h2) {
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = (c + h1->data + h2->data) % 10;
        c = (c + h1->data + h2->data) / 10;
        if (!h) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    while (h1) {
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = (c + h1->data) % 10;
        c = (c + h1->data) / 10;
        if (!h) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
        h1 = h1->next;
    }
    while (h2) {
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = (c + h2->data) % 10;
        c = (c + h2->data) / 10;
        if (!h) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
        h2 = h2->next;
    }
    if (c) {
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = c;
        if (!h) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
    }
    return h;
}

void release(node *h) {
    while (h) {
        node *n = h;
        h = h->next;
        free(n);
    }
}

int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    node *h1 = NULL, *t1 = NULL;
    node *h2 = NULL, *t2 = NULL;
    for (int i = 0; i < n; i++) {
        node *n = (node *) malloc(sizeof(node));
        int d;
        scanf("%d", &d);
        n->next = NULL;
        n->data = d;
        if (i == 0) {
            h1 = n;
            t1 = n;
        } else {
            t1->next = n;
            t1 = n;
        }
    }
    for (int i = 0; i < m; i++) {
        node *n = (node *) malloc(sizeof(node));
        int d;
        scanf("%d", &d);
        n->next = NULL;
        n->data = d;
        if (i == 0) {
            h2 = n;
            t2 = n;
        } else {
            t2->next = n;
            t2 = n;
        }
    }
    h1 = reverse(h1);
    h2 = reverse(h2);
    node *h = add(h1, h2);
    h = reverse(h);
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    release(h1);
    release(h2);
    release(h);
    return 0;
}