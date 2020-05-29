#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>

/**
 * 打印N个数组整体最大的TopK
 */
using namespace std;

typedef struct node {
    int val;
    int idx;
} node;

struct cmp {
    bool operator()(node *a, node *b) {
        return a->val < b->val;
    }
};

priority_queue<node *, vector<node *>, cmp> queue1;
vector<node *> vector1;
vector<vector<node *> > vectors;

int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        vector1.clear();
        for (int j = 0; j < c; j++) {
            node *t = (node *) malloc(sizeof(node));
            scanf("%d", &t->val);
            t->idx = i;
            vector1.push_back(t);
        }
        vectors.push_back(vector1);
    }
    for (int i = 0; i < n; i++) {
        if (vectors[i].size() > 0) {
            node *t = vectors[i][vectors[i].size() - 1];
            queue1.push(t);
            vectors[i].pop_back();
        }
    }
    while (k > 0 && !queue1.empty()) {
        node *top = queue1.top();
        printf("%d ", top->val);
        queue1.pop();
        k--;
        if (vectors[top->idx].size() > 0) {
            node *t = vectors[top->idx][vectors[top->idx].size() - 1];
            queue1.push(t);
            vectors[top->idx].pop_back();
        }
        free(top);
        top = NULL;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vectors[i].size(); j++)
            free(vectors[i][j]);
    }
    return 0;
}
