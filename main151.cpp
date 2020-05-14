#include <stdio.h>
#include <malloc.h>

typedef struct node {
    struct node *next;
    int data;
} node;

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    node *h = NULL, *t = NULL;
    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = c;
        if (i == 1) {
            h = n;
            t = n;
        } else {
            t->next = n;
            t = n;
        }
    }
    node *p = h;
    int i = 1;
    node *h2 = NULL, *t2 = NULL;
    while (i <= n / 2) {
        node *n = p->next;
        p->next = h2;
        h2 = p;
        if (!t2)
            t2 = p;
        p = n;
        i++;
    }
    t2->next = p;
    h = h2;
    if (n % 2 == 1) {
        p = p->next;
    }
    node *q = h;
    bool ok = true;
    while (p) {
        if (p->data != q->data) {
            ok = false;
            break;
        }
        p = p->next;
        q = q->next;
    }
    while (h) {
        node *n = h;
        h = h->next;
        free(n);
    }
    if (ok)
        printf("true");
    else
        printf("false");
    return 0;
}
