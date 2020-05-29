#include <stdio.h>
#include <stdlib.h>

/**
 * 在行列都排好序的矩阵中找数
 */

bool find(int **arr, int k, int a, int b, int c, int d) {
    if (a > c || b > d)
        return false;
    if (arr[c][b] == k)
        return true;
    else if (arr[c][b] < k)
        return find(arr, k, a, b + 1, c, d);
    else
        return find(arr, k, a, b, c - 1, d);
}

int main() {
    freopen("data.in", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int **arr = (int **) malloc(sizeof(int *));
    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc(sizeof(int) * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    }
    printf("%d\n", find(arr, k, 0, 0, n - 1, m - 1));
    return 0;
}