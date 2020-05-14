#include <stdio.h>
#include <map>
#include <stack>
#include <set>

/**
 * 构造数组的MaxTree
 */

using namespace std;

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} node;

map<int, node *> map1;
map<int, int> map2;
stack<int> stack1;
stack<int> stack2;

void preOrderTraverse(node *r) {
    printf("%d ", r->data);
    if (r->left)
        preOrderTraverse(r->left);
    if (r->right)
        preOrderTraverse(r->right);
}

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        node *cur = (node *) malloc(sizeof(node));
        cur->data = arr[i];
        cur->left = NULL;
        cur->right = NULL;
        map1[arr[i]] = cur;
    }
    for (int i = 0; i < n; i++) {
        while (!stack1.empty() && stack1.top() <= arr[i])
            stack1.pop();
        if (!stack1.empty())
            map2[arr[i]] = stack1.top();
        stack1.push(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!stack2.empty() && stack2.top() <= arr[i])
            stack2.pop();
        if (!stack2.empty()) {
            if (map2.find(arr[i]) == map2.end() || map2[arr[i]] > stack2.top())
                map2[arr[i]] = stack2.top();
        }
        stack2.push(arr[i]);
    }
    int r;
    for (int i = 0; i < n; i++) {
        if (map2.find(arr[i]) == map2.end()) {
            r = arr[i];
            break;
        }
    }
    for (map<int, int>::iterator iter = map2.begin(); iter != map2.end(); iter++) {
        int c = iter->first;
        int f = iter->second;
        if (map1[f]->left == NULL)
            map1[f]->left = map1[c];
        else if (map1[f]->right == NULL)
            map1[f]->right = map1[c];
    }
    preOrderTraverse(map1[r]);
    return 0;
}