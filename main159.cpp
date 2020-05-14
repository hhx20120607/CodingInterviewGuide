#include <stdio.h>
#include <malloc.h>

/**
 * 将搜索二叉树转换成双向链表
 */

typedef struct node {
    struct node *prev;
    struct node *next;
    int data;
} node;

node *nodes = NULL;
bool *has = NULL;

void midOrderTraverse(node *n, node *&h, node *&t) {
    if (n->prev)
        midOrderTraverse(n->prev, h, t);
    if (!h) {
        h = n;
        t = n;
    } else {
        t->next = n;
        n->prev = t;
        t = n;
    }
    if (n->next)
        midOrderTraverse(n->next, h, t);
}

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    nodes = (node *) malloc(sizeof(node) * (n + 1));
    has = (bool *) malloc(sizeof(bool) * (n + 1));
    for (int i = 1; i <= n; i++)
        has[i] = false;
    for (int i = 1; i <= n; i++) {
        int idx, l, r;
        scanf("%d%d%d", &idx, &l, &r);
        if (l != 0)
            nodes[idx].prev = &nodes[l];
        else
            nodes[idx].prev = NULL;
        if (r != 0)
            nodes[idx].next = &nodes[r];
        else
            nodes[idx].next = NULL;
        nodes[idx].data = idx;
        has[l] = true;
        has[r] = true;
    }
    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (has[i] == false) {
            r = i;
            break;
        }
    }
    node *h = NULL, *t = NULL;
    midOrderTraverse(&nodes[r], h, t);
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
    free(nodes);
    free(has);
    return 0;
}
