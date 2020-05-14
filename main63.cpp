#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

bool compare(char* s1,char* s2){
    int a=strlen(s1);
    int b=strlen(s2);
    strncpy(s1+a,s2,b);
    strncpy(s2+b,s1,a);
    s1[a+b]='\0';
    s2[a+b]='\0';
    int ans=strcmp(s1,s2);
    s1[a]='\0';
    s2[b]='\0';
    return ans<0;
}

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    char** arr=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
        arr[i]=(char*)malloc(sizeof(char)*(21));
    for(int i=0;i<n;i++)
        scanf("%s",arr[i]);
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
        printf("%s",arr[i]);
    return 0;
}
