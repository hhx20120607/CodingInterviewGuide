#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <vector>

/**
 * 打印二叉树的边界节点
 */
using namespace std;

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

void levelTraverse(node *t) {
    queue<node *> queue;
    map<int, vector<int>> map;
    queue.push(t);
    int i = 0;
    int j = 0;
    int c = 1;
    while (!queue.empty()) {
        node *cur = queue.front();
        queue.pop();
        if (j == 0 || j == c - 1)
            map[i].push_back(cur->data);
        if (cur->left)
            queue.push(cur->left);
        if (cur->right)
            queue.push(cur->right);
        j++;
        if (j == c) {
            i++;
            j = 0;
            c = queue.size();
        }
    }
    int height = map.size();
    for (int k = 0; k < height - 1; k++)
        printf("%d ", map[k][0]);
    for (int k = 0; k < map[height - 1].size(); k++)
        printf("%d ", map[height - 1][k]);
    for (int k = height - 2; k > 0; k--)
        printf("%d ", map[k][1]);
}

int main() {
    node *t = NULL;
    construct(t);
    levelTraverse(t);
    return 0;
}