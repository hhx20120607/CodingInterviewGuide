#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>

/**
数组排序之后相邻数的最大差值
**/

using namespace std;


int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    int *big = (int *) malloc(sizeof(int) * n);
    int *sml = (int *) malloc(sizeof(int) * n);
    int b, s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        big[i] = INT_MIN;
        sml[i] = INT_MAX;
        if (i == 0) {
            b = arr[i];
            s = arr[i];
        } else {
            b = max(b, arr[i]);
            s = min(s, arr[i]);
        }
    }
    int c = ceil((b - s) * 1.0 / n);
    if (c == 0) {
        printf("%d", 0);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int idx = ceil((arr[i] - s) * 1.0 / c);
        big[idx] = max(big[idx], arr[i]);
        sml[idx] = min(sml[idx], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (big[i] - sml[i] > ans)
            ans = big[i] - sml[i];
    }
    int pre = -1;
    for (int i = 0; i < n; i++) {
        if (big[i] != INT_MIN && sml[i] != INT_MAX) {
            if (pre != -1) {
                int temp = sml[i] - big[pre];
                if (temp > ans)
                    ans = temp;
            }
            pre = i;
        }
    }
    printf("%d", ans);
    return 0;
}
