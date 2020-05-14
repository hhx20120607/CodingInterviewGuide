#include<stdio.h>
#include <malloc.h>

/**
 * 在两个排序数组中找到第k小的数
 * @param arr1
 * @param arr2
 * @param s1
 * @param e1
 * @param s2
 * @param e2
 * @return
 */


int getMedian(int *arr1, int *arr2, int s1, int e1, int s2, int e2) {
    while (s1 < e1) {
        int m1 = (s1 + e1) / 2;
        int m2 = (s2 + e2) / 2;
        if (arr1[m1] == arr2[m2]) {
            return arr1[m1];
        } else if (arr1[m1] > arr2[m2]) {
            if ((e1 - s1 + 1) % 2 == 0) {
                e1 = m1;
                s2 = m2 + 1;
            } else {
                e1 = m1;
                s2 = m2;
            }
        } else {
            if ((e1 - s1 + 1) % 2 == 0) {
                e2 = m2;
                s1 = m1 + 1;
            } else {
                e2 = m2;
                s1 = m1;
            }
        }
    }
    return arr1[s1] < arr2[s2] ? arr1[s1] : arr2[s2];
}

int main() {
    freopen("data.in", "r", stdin);
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int *arr1 = (int *) malloc(sizeof(int) * n);
    int *arr2 = (int *) malloc(sizeof(int) * m);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);
    if (n < m) {
        int t = n;
        n = m;
        m = t;
        int *arr = arr1;
        arr1 = arr2;
        arr2 = arr;
    }
    if (k <= n && k <= m)
        printf("%d\n", getMedian(arr1, arr2, 0, k - 1, 0, k - 1));
    else if (k >= n && k >= m) {
        int a = k - m, b = k - n;
        if (arr1[a - 1] >= arr2[m - 1])
            printf("%d\n", arr1[a - 1]);
        else if (arr2[b - 1] >= arr1[n - 1])
            printf("%d\n", arr2[b - 1]);
        else
            printf("%d\n", getMedian(arr1, arr2, a, n - 1, b, m - 1));
    } else {
        int t = k;
        if (arr1[t - 1] <= arr2[0])
            printf("%d\n", arr1[t - 1]);
        else
            printf("%d\n", getMedian(arr1, arr2, k, n - 1, 0, m - 1));
    }
    return 0;
}