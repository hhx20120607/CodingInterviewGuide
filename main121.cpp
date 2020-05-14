#include<stdio.h>
#include <malloc.h>

/**
 * 在有序旋转数组中找到一个数
 * @param arr
 * @param k
 * @param l
 * @param r
 * @return
 */

int find(int *arr, int k, int l, int r) {
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] == k)
            return m;
        if (arr[m] < arr[r]) {
            if (k > arr[m] && k <= arr[r])
                l = m + 1;
            else
                r = m - 1;
        } else if (arr[m] > arr[l]) {
            if (k >= arr[l] && k < arr[m])
                r = m - 1;
            else
                l = m + 1;
        } else {
            r=m-1;
        }
    }
    if (arr[l] == k)
        return l;
    else
        return -1;
}

int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if (find(arr, m, 0, n - 1) != -1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}