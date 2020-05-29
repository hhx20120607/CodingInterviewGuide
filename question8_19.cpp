#include<stdio.h>
#include<float.h>
#include<algorithm>

/**
 * 数组中子数组的最大累乘积
 */
using namespace std;

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    double b, s, ans = DBL_MIN;
    for (int i = 0; i < n; i++) {
        double c;
        scanf("%lf", &c);
        if (i == 0) {
            b = c;
            s = c;
        } else {
            if (c > 0) {
                b = max(c, c * b);
                s = min(c, c * s);
            } else if (c < 0) {
                double t = b;
                b = max(c, c * s);
                s = min(c, c * t);
            } else {
                b = 0;
                s = 0;
            }
        }
        ans = max(ans, b);
    }
    printf("%.2f\n", ans);
    return 0;
}
