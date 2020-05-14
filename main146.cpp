#include <stdio.h>
#include <malloc.h>
#include <cmath>

/**
 * 删除链表的中间节点和a/b处的节点
 */

typedef struct node {
    struct node *next;
    int data;
} node;

int main() {
    freopen("data.in", "r", stdin);
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
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
    double d = 1.0 * a / b * n;
    int k = floor(d + 0.5);
    if (d > k)
        k++;
    node *p = NULL;
    if (k == 1) {
        p = h;
        h = h->next;
        free(p);
    } else {
        p = h;
        int i = 1;
        while (i < k - 1 && p) {
            p = p->next;
            i++;
        }
        if (i == k - 1 && p && p->next) {
            node *q = p->next;
            p->next = p->next->next;
            free(q);
        }
    }
    p = h;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    p = h;
    while (p) {
        node *q = p->next;
        free(p);
        p = q;
    }
    return 0;
}