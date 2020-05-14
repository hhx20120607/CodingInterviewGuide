#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<vector>

/**
 * 一种字符串和数字的对应关系
 */

using namespace std;

map<char, int> map1;
map<int, char> map2;

int main() {
    freopen("data.in", "r", stdin);
    int o, n;
    scanf("%d%d", &o, &n);
    char *s = (char *) malloc(sizeof(n + 1));
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        map1[s[i]] = i + 1;
        map2[i + 1] = s[i];
    }
    if(o==1){
        int c;
        scanf("%d",&c);
        vector<int> vector1;
        while(c){
            int t=c%n;
            if(t==0){
                vector1.push_back(n);
                c-=n;
            }
            else{
                vector1.push_back(t);
                c-=t;
            }
            c/=n;
        }
        for(int i=0;i<vector1.size();i++)
            printf("%c",map2[vector1[vector1.size()-1-i]]);
    }
    else{
        string d;
        cin>>d;
        int sum=0;
        for(int i=0;i<d.size();i++){
            sum=sum*n+map1[d[i]];
        }
        printf("%d\n",sum);
    }
    return 0;
}
