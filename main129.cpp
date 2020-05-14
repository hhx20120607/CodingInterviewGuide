#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#include <malloc.h>
#include <algorithm>

/**
 * 两个有序数组间相加和的TOP K问题
 */

using namespace std;

typedef struct {
    int i;
    int j;
    long long s;
} rcd;

struct cmp {
    bool operator()(rcd a, rcd b) {
        return a.s < b.s;
    }
};

priority_queue<rcd, vector<rcd>, cmp> queue1;
map<int, map<int, bool>> map1;

int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    int *arr1 = (int *) malloc(sizeof(int) * n);
    int *arr2 = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr2[i]);
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + n);
    rcd c = {n - 1, n - 1, arr1[n - 1] + arr2[n - 1]};
    queue1.push(c);
    map1[n - 1][n - 1] = true;
    int cnt = 0;
    while (cnt < k && !queue1.empty()) {
        rcd t = queue1.top();
        int i = t.i;
        int j = t.j;
        queue1.pop();
        printf("%d ", t.s);
        if (i - 1 >= 0 && !map1[i - 1][j]) {
            rcd n = {i - 1, j, arr1[i - 1] + arr2[j]};
            queue1.push(n);
            map1[i - 1][j] = true;
        }
        if (j - 1 >= 0 && !map1[i][j - 1]) {
            rcd n = {i, j - 1, arr1[i] + arr2[j - 1]};
            queue1.push(n);
            map1[i][j - 1] = true;
        }
        cnt++;
    }
    return 0;
}