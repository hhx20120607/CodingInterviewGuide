#include <stdio.h>
#include <malloc.h>

typedef struct node {
    struct node *next;
    struct node *rand;
    int data;
} node;

void copy(node *s, node *&d) {
    node *n = s;
    node *t = NULL;
    while (n) {
        node *c = (node *) malloc(sizeof(node));
        c->next = NULL;
        c->rand = n->rand;
        c->data = n->data;
        n->rand = c;
        if (!d) {
            d = c;
            t = c;
        } else {
            t->next = c;
            t = c;
        }
        n = n->next;
    }
    n = d;
    while (n) {
        n->rand = n->rand->rand;
        n=n->next;
    }
}

int main() {
    return 0;
}