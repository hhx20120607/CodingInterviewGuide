#include <stdio.h>
#include <malloc.h>

/**
 * 反转部分单向链表
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
        int c;
        scanf("%d", &c);
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = c;
        if (i == 0) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
    }
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 1)
        t = NULL;
    node *h2 = NULL, *t2 = NULL;
    node *p = h;
    int i = 1;
    while (i <= b && p) {
        node *n = p->next;
        if (i >= a) {
            if (!t2)
                t2 = p;
            p->next = h2;
            h2 = p;
        } else if (i == a - 1) {
            t = p;
            p->next = NULL;
        }
        p = n;
        i++;
    }
    if (t) {
        while (h) {
            printf("%d ", h->data);
            node *n=h;
            h = h->next;
            free(n);
        }
    }
    if (t2) {
        while (h2) {
            printf("%d ", h2->data);
            node *n=h2;
            h2 = h2->next;
            free(n);
        }
    }
    while (p) {
        printf("%d ", p->data);
        node *n = p;
        p = p->next;
        free(n);
    }
    return 0;
}