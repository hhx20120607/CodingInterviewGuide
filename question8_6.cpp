#include<stdio.h>
#include<map>
#include<vector>

/**
 * 在数组中找到出现次数大于N/K的数
 */
using namespace std;

map<int, int> map1;

int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        if (map1.find(arr[i]) != map1.end()) {
            map1[arr[i]]++;
        } else if (map1.size() < k - 1) {
            map1[arr[i]] = 1;
        } else {
            vector<map<int, int>::iterator> vector1;
            for (map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter++) {
                iter->second--;
                if (iter->second == 0)
                    vector1.push_back(iter);
            }
            for (vector<map<int, int>::iterator>::iterator iter = vector1.begin(); iter != vector1.end(); iter++) {
                map1.erase(*iter);
            }
        }
    }
    for (map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter++) {
        iter->second = 0;
    }
    for (int i = 0; i < n; i++) {
        map1[arr[i]]++;
    }
    int ok = 0;
    for (map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter++) {
        if (iter->second > n / k) {
            ok = 1;
            break;
        }
    }
    if (ok) {
        for (map<int, int>::iterator iter = map1.begin(); iter != map1.end(); iter++) {
            if (iter->second > n / k) {

                printf("%d", iter->first);
                if (iter != map1.end())
                    printf(" ");
                else
                    printf("\n");
            }
        }
    } else {
        printf("-1\n");
    }
    return 0;
}
