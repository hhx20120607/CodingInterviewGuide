#include <stdio.h>
#include <stack>
#include <map>

/**
 * 分别用递归和非递归方式实现二叉树先序、中序和后序遍历
 *  https://www.nowcoder.com/practice/566f7f9d68c24691aa5abd8abefa798c?tpId=101&tqId=33229&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-rankings
 */

using namespace std;

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} node;


/**
 * 标志法
 * @param t
 */
void preOrderTraverse(node *t) {
    if (t == NULL)
        return;
    stack<node *> stack1;
    map<node *, int> map1;
    stack1.push(t);
    while (!stack1.empty()) {
        node *c = stack1.top();
        switch (map1[c]) {
            case 0:
                printf("%d\n", c->data);
                map1[c] = 1;
                break;
            case 1:
                if (c->left != NULL)
                    stack1.push(c->left);
                map1[c] = 2;
                break;
            case 2:
                if (c->right != NULL)
                    stack1.push(c->right);
                map1[c] = 3;
                break;
            case 3:
                stack1.pop();
                break;
        }
    }
}

/**
 * 标志法
 * @param t
 */
void midOrderTraverse(node *t) {
    if (t == NULL)
        return;
    stack<node *> stack1;
    map<node *, int> map1;
    stack1.push(t);
    while (!stack1.empty()) {
        node *c = stack1.top();
        switch (map1[c]) {
            case 0:
                if (c->left)
                    stack1.push(c->left);
                map1[c] = 1;
                break;
            case 1:
                printf("%d\n", c->data);
                map1[c] = 2;
                break;
            case 2:
                if (c->right != NULL)
                    stack1.push(c->right);
                map1[c] = 3;
                break;
            case 3:
                stack1.pop();
                break;
        }
    }
}

/**
 * 标志法
 * @param t
 */
void postOrderTraverse(node *t) {
    if (t == NULL)
        return;
    stack<node *> stack1;
    map<node *, int> map1;
    stack1.push(t);
    while (!stack1.empty()) {
        node *c = stack1.top();
        switch (map1[c]) {
            case 0:
                if (c->left)
                    stack1.push(c->left);
                map1[c] = 1;
                break;
            case 1:
                if (c->right != NULL)
                    stack1.push(c->right);
                map1[c] = 2;
                break;
            case 2:
                printf("%d\n", c->data);
                map1[c] = 3;
                break;
            case 3:
                stack1.pop();
                break;
        }
    }
}


/**
 * 传统方法
 * @param t
 */
void preOrderTraverse2(node *t) {
    if (t == NULL)
        return;
    stack<node *> stack1;
    stack1.push(t);
    while (!stack1.empty()) {
        node *c = stack1.top();
        stack1.pop();
        printf("%d\n", c->data);
        if (c->right)
            stack1.push(c->right);
        if (c->left)
            stack1.push(c->left);
    }
}

/**
 * 传统方法
 * @param t
 */
void midOrderTraverse2(node *t) {
    stack<node *> stack1;
    node *c = t;
    while (c != NULL || stack1.size() != 0) {
        if (c != NULL) {
            stack1.push(c);
            c = c->left;
        } else {
            c = stack1.top();
            stack1.pop();
            printf("%d\n", c->data);
            c = c->right;
        }
    }
}

/**
 * 传统方法
 * @param t
 */
void postOrderTraverse2(node *t) {
    if (t == NULL)
        return;
    stack<node *> stack1, stack2;
    stack1.push(t);
    while (!stack1.empty()) {
        node *c = stack1.top();
        stack1.pop();
        stack2.push(c);
        if (c->left)
            stack1.push(c->left);
        if (c->right)
            stack1.push(c->right);
    }
    while (!stack2.empty()) {
        printf("%d\n", stack2.top()->data);
        stack2.pop();
    }
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
    return 0;
}