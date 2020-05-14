#include <stdio.h>
#include <malloc.h>

/**
 * 打印两个有序链表的公共部分
 */

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    freopen("data.in", "r", stdin);
    int a, b;
    node *h1 = NULL, *t1 = NULL;
    node *h2 = NULL, *t2 = NULL;
    scanf("%d", &a);
    while (a > 0) {
        int c;
        scanf("%d", &c);
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = c;
        if (h1 == NULL) {
            h1 = n;
            t1 = n;
        } else {
            t1->next = n;
            t1 = n;
        }
        a--;
    }
    scanf("%d", &b);
    while (b > 0) {
        int c;
        scanf("%d", &c);
        node *n = (node *) malloc(sizeof(node));
        n->next = NULL;
        n->data = c;
        if (h2 == NULL) {
            h2 = n;
            t2 = n;
        } else {
            t2->next = n;
            t2 = n;
        }
        b--;
    }
    while (h1 && h2) {
        if (h1->data < h2->data)
            h1 = h1->next;
        else if (h1->data > h2->data)
            h2 = h2->next;
        else {
            printf("%d ", h1->data);
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    return 0;
}