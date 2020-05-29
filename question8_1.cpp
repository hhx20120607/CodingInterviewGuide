#include <stdio.h>
#include <stdlib.h>

/**
 * ×ªÈ¦´òÓ¡¾ØÕó
 * @return
 */
int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int **arr = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc(sizeof(int) * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    }
    int i = 0, j = 0;
    int k = 0, d = 1, s = n * m;
    int left = 0, right = m - 1, up = 0, down = n - 1;
    while (k < s) {
        while (j <= right) {
            printf("%d ", arr[i][j]);
            j++;
            k++;
        }
        j--;
        i++;
        up++;
        while (i <= down) {
            printf("%d ", arr[i][j]);
            i++;
            k++;
        }
        i--;
        j--;
        right--;
        while (j >= left) {
            printf("%d ", arr[i][j]);
            j--;
            k++;
        }
        j++;
        i--;
        down--;
        while (i >= up) {
            printf("%d ", arr[i][j]);
            i--;
            k++;
        }
        i++;
        j++;
        left++;
    }


    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
