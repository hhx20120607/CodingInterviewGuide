#include <stdio.h>
#include <malloc.h>

/**
 * 单链表的选择排序
 */

typedef struct node {
    struct node *next;
    int data;
} node;

node *getPrevOfMin(node *h) {
    node *p = NULL;
    node *q = h;
    node *prev = h;
    node *cur = h->next;
    while (cur) {
        if (cur->data < q->data) {
            p = prev;
            q = cur;
        }
        prev = cur;
        cur = cur->next;
    }
    return p;
}

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
    node *h2 = NULL, *t2 = NULL;
    node *p = NULL, *q = NULL, *s = h;
    while (s) {
        p = getPrevOfMin(s);
        if (!p) {
            q = s;
            h = h->next;
        } else {
            q = p->next;
            p->next = p->next->next;
        }
        if (!h2) {
            h2 = q;
            t2 = q;
        } else {
            t2->next = q;
            t2 = q;
        }
        s = h;
    }
    while (h2) {
        printf("%d ", h2->data);
        node *n = h2->next;
        free(h2);
        h2 = n;
    }
}