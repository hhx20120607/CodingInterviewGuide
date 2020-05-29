#include<stdio.h>
#include<stdlib.h>

/**
 * 在数组中找到一个局部最小的位置
 */
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    if (arr[1] > arr[0])
        return 0;
    if (arr[n - 2] > arr[n - 1])
        return n - 1;
    int i = 1, j = n - 2;
    while (i < j) {
        int m = (i + j) / 2;
        if (arr[m] > arr[m - 1])
            j = m - 1;
        else if (arr[m] > arr[m + 1])
            i = m + 1;
        else {
            printf("%d\n", m);
            return 0;
        }
    }
    printf("%d\n", i);
    return 0;
}
