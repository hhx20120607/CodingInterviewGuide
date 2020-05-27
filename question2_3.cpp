#include <stdio.h>
#include <stdlib.h>

/**
 * 如何较为直观地打印二叉树
 */
typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} node;

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

void printTree(node *t, int level) {
    if (t->right)
        printTree(t->right, level + 1);
    for (int i = 0; i < level; i++)
        printf("\t");
    printf("%d\n", t->data);
    if (t->left)
        printTree(t->left, level + 1);
}

int main() {
    node *t = NULL;
    construct(t);
    printTree(t, 0);
    return 0;
}