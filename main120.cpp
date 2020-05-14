#include<stdio.h>
#include <malloc.h>

/**
 * 在有序旋转数组中找到最小值
 * @return
 */

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int l = 0, r = n - 1;
    while (l < r) {
        if (arr[l] < arr[r])
            break;
        int m = (l + r) / 2;
        if (arr[m] < arr[r])
            r = m;
        else if (arr[m] > arr[l])
            l = m + 1;
        else {
            break;
        }
    }
    printf("%d\n", arr[l]);
    return 0;
}