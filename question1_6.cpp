#include<stdio.h>
#include <cstring>

/**
 * 用栈来求解汉诺塔问题
 */
int move(const char *left, const char *right, const char *mid, int a, int b) {
    if (a == b) {
        if (strcmp(left, "mid") == 0 || strcmp(right, "mid") == 0) {
            printf("Move %d from %s to %s\n", a, left, right);
            return 1;
        } else {
            printf("Move %d from %s to %s\n", a, left, mid);
            printf("Move %d from %s to %s\n", a, mid, right);
            return 2;
        }
    }
    int s = 0;
    s += move(left, right, mid, a, b - 1);
    s += move(left, mid, right, b, b);
    s += move(right, left, mid, a, b - 1);
    s += move(mid, right, left, b, b);
    s += move(left, right, mid, a, b - 1);
    return s;
}

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    const char *left = "left";
    const char *right = "right";
    const char *mid = "mid";
    int s = move(left, right, mid, 1, n);
    printf("It will move %d steps.\n", s);
    return 0;
}