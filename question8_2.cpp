#include<stdio.h>
#include<stdlib.h>


/**
 * 将正方形矩阵顺时针转动90°
 */


void rotateEdge(int **arr, int a, int b, int c, int d) {
    int k = c - a;
    for (int i = 0; i < k; i++) {
        int t = arr[a][b + i];
        arr[a][b + i] = arr[c - i][b];
        arr[c - i][b] = arr[c][d - i];
        arr[c][d - i] = arr[a + i][d];
        arr[a + i][d] = t;
    }
}


int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int **arr = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        arr[i] = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    }
    for (int i = 0; i < n / 2; i++) {
        rotateEdge(arr, i, i, n - 1 - i, n - 1 - i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}


