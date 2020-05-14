#include<stdio.h>
#include <cmath>

/**
 * 1到n中1出现的次数
 * @param a
 * @return
 */

int getDigit(long long a) {
    if (a == 0)
        return 1;
    int k = 0;
    while (a) {
        a = a / 10;
        k++;
    }
    return k;
}

long long getCount(long long a, long long b) {
    if (b < 10)
        return 1;
    long long s = 0;
    int k = getDigit(b);
    long long t = (long long) (pow(10, k - 1) + 0.5);
    long long c = b / t;
    if (c > 1)
        s += t;
    else
        s = s + b % t + 1;
    s += (k - 1) * t / 10 * c;
    return s;
}

long long getCount(long long b) {
    long long s = 0;
    int k = getDigit(b);
    long long t = (long long) pow(10, k - 1);
    while (b != 0) {
        long long a = b % t + 1;
        s += getCount(a, b);
        b = a - 1;
        t /= 10;
    }
    return s;
}


int main() {
    freopen("data.in", "r", stdin);
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", getCount(n));
    return 0;
}
