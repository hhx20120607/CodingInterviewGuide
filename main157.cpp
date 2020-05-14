#include <stdio.h>
#include <malloc.h>
#include <set>

/**
 * 删除无序单链表中值重复出现的节点
 */

using namespace std;

typedef struct node {
    struct node *next;
    int data;
} node;

set<int> set1;

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
    node *c = h;
    h = NULL;
    t = NULL;
    while (c) {
        if (set1.find(c->data) == set1.end()) {
            set1.insert(c->data);
            if (!h) {
                h = c;
                t = c;
            } else {
                t->next = c;
                t = c;
            }
            c = c->next;
        } else {
            node *t = c;
            c = c->next;
            free(t);
        }
    }
    t->next = NULL;
    while (h) {
        printf("%d ", h->data);
        node *t = h;
        h = h->next;
        free(t);
    }
    return 0;
}
