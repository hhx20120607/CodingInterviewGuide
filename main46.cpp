#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
判断两个字符串是否互为变形词
https://www.nowcoder.com/practice/b07c464a107e421ebbd2c82aebd42e39?tpId=101&tqId=33163&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int hash[256];

int main(){
    freopen("data.in","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    char* arr1=(char*)malloc(sizeof(char)*(m+1));
    char* arr2=(char*)malloc(sizeof(char)*(n+1));
    scanf("%s",arr1);
    scanf("%s",arr2);
    memset(hash,0,256);
    for(int i=0;i<m;i++)
        hash[arr1[i]]+=1;
    for(int i=0;i<n;i++)
        hash[arr2[i]]-=1;
    bool ok=1;
    for(int i=0;i<256;i++){
        if(hash[i]!=0){
            ok=0;
            break;
        }
    }
    if(ok)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
