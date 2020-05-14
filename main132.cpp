#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

void fun1() {
    string s;
    cin >> s;
    int len = 2 * s.size() + 1;
    char *t = (char *) malloc(sizeof(char) * (len + 1));
    int *arr = (int *) malloc(sizeof(int) * len);
    int j = 0;
    for (int i = 0; i < len; i++) {
        t[i] = i % 2 == 0 ? '#' : s[j++];
    }
    int idx = -1, pR = -1;
    int ans = 1;
    for (int i = 0; i < len; i++) {
        int r = 1;
        if (i < pR) {
            if (i + arr[2 * idx - i] < pR) {
                r = arr[2 * idx - i];
            } else {
                r = pR - i;
            }
        }
        while (i + r < len && i - r >= 0) {
            if (t[i + r] == t[i - r])
                r++;
            else
                break;
        }
        arr[i] = r;
        if (i + r > pR) {
            pR = i + r;
            idx = i;
        }
        if (r > ans)
            ans = r;
    }
    printf("%d\n", ans - 1);
    free(t);
    free(arr);
}

void fun2() {
    string s;
    cin >> s;
    int len = 2 * s.size() + 1;
    char *t = (char *) malloc(sizeof(char) * (len + 1));
    int *arr = (int *) malloc(sizeof(int) * len);
    int j = 0;
    for (int i = 0; i < len; i++) {
        t[i] = i % 2 == 0 ? '#' : s[j++];
    }
    int idx = -1, pR = -1;
    for (int i = 0; i < len; i++) {
        int r = 1;
        if (i < pR) {
            if (i + arr[2 * idx - i] < pR) {
                r = arr[2 * idx - i];
            } else {
                r = pR - i;
            }
        }
        while (i + r < len && i - r >= 0) {
            if (t[i + r] == t[i - r])
                r++;
            else
                break;
        }
        arr[i] = r;
        if (i + r > pR) {
            pR = i + r;
            idx = i;
        }
    }
    int ans = -1;
    for (int i = 0; i < len; i++) {
        if (i + arr[i] - 1 == len - 1) {
            ans = i;
            break;
        }
    }
    for (int i = ans - arr[ans]; i >= 0; i--) {
        if (i % 2 == 1)
            printf("%c", t[i]);
    }
    free(t);
    free(arr);

}

int main() {
    freopen("data.in", "r", stdin);
    fun2();
    return 0;
}