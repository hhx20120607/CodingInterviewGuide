#include <stdio.h>
#include <malloc.h>

typedef struct node {
    struct node *next;
    int data;
} node;

void fun(node *&h, node *&t, node *n) {
    if (!h) {
        h = n;
        t = n;
    } else {
        t->next = n;
        t = n;
    }
}

int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    node *h1 = NULL, *t1 = NULL;
    node *h2 = NULL, *t2 = NULL;
    node *h3 = NULL, *t3 = NULL;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        node *n = (node *) malloc(sizeof(node));
        n->data = d;
        n->next = NULL;
        if (d < k) {
            fun(h1, t1, n);
        } else if (d == k) {
            fun(h2, t2, n);
        } else {
            fun(h3, t3, n);
        }
    }
    if (t1) {
        t1->next = h2 ? h2 : h3;
    }
    if (t2) {
        t2->next = h3;
    }
    node *h = NULL;
    if (h1)
        h = h1;
    else if (h2)
        h = h2;
    else
        h = h3;
    while (h) {
        node *n = h;
        printf("%d ", h->data);
        h = h->next;
        free(n);
    }
    return 0;
}