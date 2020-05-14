#include <stdio.h>
#include <malloc.h>

/**
 * 在单链表和双链表中删除倒数第k个节点
 */

typedef struct node {
    struct node *next;
    int data;
} node;

int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
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
    k = n - k;
    node *p = NULL;
    if (k == 0) {
        p = h;
        h = h->next;
        free(p);
    } else {
        p = h;
        int i = 1;
        while (i < k && p) {
            p = p->next;
            i++;
        }
        if (i == k && p && p->next) {
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