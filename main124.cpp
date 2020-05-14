#include<stdio.h>
#include <malloc.h>

/**
 * 一种消息接收并打印的结构设计
 * @return
 */


int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    bool *has = (bool *) malloc(sizeof(bool) * (n + 1));
    for (int i = 0; i < n + 1; i++)
        has[i] = false;
    int nxt = 1;
    for (int i = 0; i < n; i++) {
        int cur;
        scanf("%d", &cur);
        has[cur] = true;
        if (cur == nxt) {
            int tmp = nxt;
            while (has[tmp] && tmp <= n) {
                printf("%d %d\n", tmp, nxt);
                tmp++;
            }
            nxt = tmp;
        }
    }
    return 0;
}