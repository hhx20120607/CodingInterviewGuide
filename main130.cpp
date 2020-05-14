#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include <iostream>

using namespace std;

typedef struct {
    string s;
    int c;
} rcd;

struct cmp {
    bool operator()(rcd r1, rcd r2) {
        if (r1.c != r2.c)
            return r1.c > r2.c;
        return r1.s < r2.s;
    }
};

priority_queue<rcd, vector<rcd>, cmp> queue1;
map<string, int> map1;
vector<rcd> vector1;

int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        map1[s]++;
    }
    for (map<string, int>::iterator iter = map1.begin(); iter != map1.end(); iter++) {
        rcd t = {iter->first, iter->second};
        queue1.push(t);
        if (queue1.size() > k) {
            queue1.pop();
        }
    }
    while (!queue1.empty()) {
        rcd t = queue1.top();
        vector1.push_back(t);
        queue1.pop();
    }
    for (int i = 0; i < vector1.size(); i++) {
        rcd t = vector1[vector1.size() - 1 - i];
        cout << t.s << " " << t.c << endl;
    }
    return 0;
}