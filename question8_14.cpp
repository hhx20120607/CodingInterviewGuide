#include<stdio.h>
#include<stdlib.h>

/**
 * 自然数组的排序
 */
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int i = 0;
    while (i < n) {
        while (arr[i] != i + 1) {
            int j = arr[i] - 1;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        i++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
