#include<stdio.h>
#include<string>
#include <iostream>
#include <vector>

using namespace std;

void getNext(string s, int *next) {
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int j = 0;
    while (i < s.size()) {
        if (s[i - 1] == s[j]) {
            next[i++] = ++j;
        } else if (j > 0) {
            j = next[j];
        } else {
            next[i++] = 0;
        }
    }
}

int indexOf(string s1, string s2) {
    int i = 0, j = 0;
    int *next = (int *) malloc(sizeof(int) * s2.size());
    getNext(s2, next);
    vector<int> vector1;
    while (true) {
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                if (next[j] == -1) {
                    i++;
                    j=0;
                } else {
                    j = next[j];
                }
            }
        }
        if (j == s2.size()) {
            vector1.push_back(i - j);
        } else
            break;
        j = 0;
    }
    if (vector1.size() == 0)
        printf("-1");
    else {
        for (int e:vector1) {
            printf("%d ", e);
        }
    }
}

int main() {
    freopen("data.in", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    indexOf(s1, s2);
    return 0;
}