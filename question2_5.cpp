#include <stdio.h>
#include <stdlib.h>

/**
 * 遍历二叉树的神级方法
 */
typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} node;

void preOrderTraverse(node *t) {
    node *cur = t;
    while (cur) {
        node *left = cur->left;
        if (left) {
            while (left->right && left->right != cur)
                left = left->right;
            if (left->right) {
                left->right = NULL;
                cur = cur->right;
            } else {
                left->right = cur;
                printf("%d\n", cur->data);
                cur = cur->left;
            }
        } else {
            printf("%d\n", cur->data);
            cur = cur->right;
        }
    }
}

void midOrderTraverse(node *t) {
    node *cur = t;
    while (cur) {
        node *left = cur->left;
        if (left) {
            while (left->right && left->right != cur)
                left = left->right;
            if (left->right) {
                left->right = NULL;
                printf("%d\n", cur->data);
                cur = cur->right;
            } else {
                left->right = cur;
                cur = cur->left;
            }
        } else {
            printf("%d\n", cur->data);
            cur = cur->right;
        }
    }
}

node *invertList(node *h) {
    node *r = NULL;
    while (h) {
        node *n = h->right;
        h->right = r;
        r = h;
        h = n;
    }
    return r;
}


void printReverseEdge(node *t) {
    t = invertList(t);
    while (t) {
        printf("%d\n", t->data);
        if (t->right)
            t = t->right;
        else
            break;
    }
    invertList(t);
}

void postOrderTraverse(node *t) {
    node *cur = t;
    while (cur) {
        node *left = cur->left;
        if (left) {
            while (left->right && left->right != cur)
                left = left->right;
            if (left->right) {
                left->right = NULL;
                printReverseEdge(cur->left);
                cur = cur->right;
            } else {
                left->right = cur;
                cur = cur->left;
            }
        } else {
            printReverseEdge(cur->left);
            cur = cur->right;
        }
    }
    printReverseEdge(t);
}


static void construct(node *&t) {
    int data;
    scanf("%d", &data);
    if (data) {
        t = (node *) malloc(sizeof(node));
        t->data = data;
        construct(t->left);
        construct(t->right);
    } else
        t = NULL;
}


int main() {
    node *t = NULL;
    construct(t);
    postOrderTraverse(t);
    return 0;
}