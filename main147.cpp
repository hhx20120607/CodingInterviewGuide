#include <stdio.h>
#include <malloc.h>

/**
 * 反转单向和双向链表
 */

typedef struct node {
    struct node *next;
    struct node *prev;
    int data;
} node;

int main() {
    freopen("data.in", "r", stdin);
    int a;
    scanf("%d", &a);
    node *h1 = NULL, *t1 = NULL;
    for (int i = 0; i < a; i++) {
        int c;
        scanf("%d", &c);
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->prev = NULL;
        n->data = c;
        if (i == 0) {
            h1 = n;
            t1 = n;
        } else {
            t1->next = n;
            t1 = n;
        }
    }
    node *p = NULL;
    while (h1) {
        node *n = h1->next;
        h1->next = p;
        p = h1;
        h1 = n;
    }
    while (p) {
        printf("%d ", p->data);
        node *t = p;
        p = p->next;
        free(t);
    }
    printf("\n");
    int b;
    scanf("%d", &b);
    node *h2 = NULL, *t2 = NULL;
    for (int i = 0; i < b; i++) {
        int c;
        scanf("%d", &c);
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->prev = NULL;
        n->data = c;
        if (i == 0) {
            h2 = n;
            t2 = n;
        } else {
            t2->next = n;
            n->prev = t2;
            t2 = n;
        }
    }
    node *q = NULL;
    while (h2) {
        node *n = h2->next;
        h2->next = q;
        if (q)
            q->prev = h2;
        q = h2;
        h2 = n;
    }
    while (q) {
        printf("%d ", q->data);
        node *t = q;
        q = q->next;
        free(t);
    }
    return 0;
}