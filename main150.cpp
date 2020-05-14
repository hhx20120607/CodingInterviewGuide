#include <stdio.h>

/**
 * 环形单链表的约瑟夫问题：进阶
 */

int main() {
    freopen("data.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int i = 1, j = 1;
    while (i < n) {
        j = (j + m) % (i + 1);
        if (j == 0)
            j = i + 1;
        i++;
    }
    printf("%d", j);
    return 0;
}