#include<stdio.h>
#include<stdlib.h>


/**
 * "Ö®"×ÖÐÎ´òÓ¡¾ØÕó
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
    int k = 0, s = n * m;
    while (k < s) {
        while (i >= 0 && j <= m - 1) {
            printf("%d ", arr[i][j]);
            i--;
            j++;
            k++;
        }
        i++;
        j--;
        if (j + 1 <= m - 1)
            j++;
        else
            i++;
        while (i <= n - 1 && j >= 0) {
            printf("%d ", arr[i][j]);
            i++;
            j--;
            k++;
        }
        i--;
        j++;
        if (i + 1 <= n - 1)
            i++;
        else
            j++;
    }
    return 0;
}
