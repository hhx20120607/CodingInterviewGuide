#include<stdio.h>
#include<stdlib.h>
#include<queue>

/**
求最短通路
**/

using namespace std;

typedef struct {
    int x;
    int y;
    int v;
} node;

queue<node *> queue1;

int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    fgetc(stdin);
    bool **arr = (bool **) malloc(sizeof(bool *) * n);
    bool **vst = (bool **) malloc(sizeof(bool *) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (bool *) malloc(sizeof(bool) * m);
        vst[i] = (bool *) malloc(sizeof(bool) * m);
        for (int j = 0; j < m; j++) {
            char c = fgetc(stdin);
            arr[i][j] = c == '1' ? true : false;
            vst[i][j] = false;
        }
        fgetc(stdin);
    }
    if (!arr[0][0]) {
        printf("-1\n");
        return 0;
    }
    node *t = (node *) malloc(sizeof(node));
    t->x = 0;
    t->y = 0;
    t->v = 1;
    queue1.push(t);
    vst[0][0] = true;
    bool ok = 0;
    while (!queue1.empty()) {
        node *c = queue1.front();
        int tx = c->x;
        int ty = c->y;
        queue1.pop();
        if (c->x == n - 1 && c->y == m - 1) {
            printf("%d\n", c->v);
            ok = 1;
        } else {
            int i = 0, j;
            for (j = -1; j <= 1; j += 2) {
                int x = c->x + i;
                int y = c->y + j;
                if (x >= 0 && x < n && y >= 0 && y < m && !vst[x][y] && arr[x][y]) {
                    node *t = (node *) malloc(sizeof(node));
                    t->x = x;
                    t->y = y;
                    t->v = c->v + 1;
                    queue1.push(t);
                    vst[x][y] = true;
                }
            }
            j = 0;
            for (i = -1; i <= 1; i += 2) {
                int x = c->x + i;
                int y = c->y + j;
                if (x >= 0 && x < n && y >= 0 && y < m && !vst[x][y] && arr[x][y]) {
                    node *t = (node *) malloc(sizeof(node));
                    t->x = x;
                    t->y = y;
                    t->v = c->v + 1;
                    queue1.push(t);
                    vst[x][y] = true;
                }
            }
        }
        free(c);
    }
    if (!ok)
        printf("-1\n");
    for (int i = 0; i < n; i++) {
        free(arr[i]);
        free(vst[i]);
    }
    free(arr);
    free(vst);
    return 0;
}
