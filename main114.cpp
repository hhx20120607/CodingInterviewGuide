#include<stdio.h>
#include <malloc.h>
/**
 * 路径数组变为统计数组
 * @return
 */
int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int* arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int cap = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == i) {
            cap = i;
            break;
        }
    }
    int i = 0;
    while (i < n) {
        int j = i;
        int k = 0;
        while (true) {
            if (j != cap && j >= i) {
                k++;
                j = arr[j];
            } else {
                break;
            }
        }
        if (j == cap)
            arr[i] = k;
        else
            arr[i] = k + arr[j];
        i++;
    }
    for (i = 0; i < n; i++)
        arr[i] = -arr[i];
    i = 0;
    while (i < n) {
        if (arr[i] < 0) {
            int j = -arr[i];
            arr[i] = 0;
            while (true) {
                if (arr[j] < 0) {
                    int t = -arr[j];
                    arr[j] = 1;
                    j = t;
                } else {
                    arr[j]++;
                    break;
                }
            }
        }
        i++;
    }
    arr[0] = 1;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
