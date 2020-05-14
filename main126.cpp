#include<stdio.h>
#include<queue>

/**
 * 随时找到数据流的中位数
 */

using namespace std;

priority_queue<int, vector<int>, less<int> > queue1;
priority_queue<int, vector<int>, greater<int> > queue2;

void add(int t) {
    if (queue1.empty()) {
        queue1.push(t);
    } else if (t > queue1.top()) {
        queue2.push(t);
    } else {
        queue1.push(t);
    }
    int size1 = queue1.size();
    int size2 = queue2.size();
    while (size1 - size2 >= 2 || size1 - size2 <= -2) {
        if (size1 > size2) {
            int top = queue1.top();
            queue1.pop();
            queue2.push(top);
        } else {
            int top = queue2.top();
            queue2.pop();
            queue1.push(top);
        }
        size1 = queue1.size();
        size2 = queue2.size();
    }
}

int getMedian(double &ans) {
    if (queue1.empty() && queue2.empty()) {
        return -1;
    }
    if (queue1.empty()) {
        ans = queue2.top();
    } else if (queue2.empty()) {
        ans = queue1.top();
    } else {
        if (queue1.size() == queue2.size()) {
            ans = (queue1.top() + queue2.top()) / 2.0;
        } else if (queue1.size() > queue2.size()) {
            ans = queue1.top();
        } else {
            ans = queue2.top();
        }
    }
    return 0;
}

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int o;
        scanf("%d", &o);
        if (o == 1) {
            int t;
            scanf("%d", &t);
            add(t);
        } else {
            double ans;
            if (getMedian(ans) != -1)
                printf("%.1lf\n", ans);
            else
                printf("-1\n");
        }
    }
    return 0;
}