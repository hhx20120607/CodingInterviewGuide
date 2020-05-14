#include<stdio.h>
#define maxn 100002

char s[maxn];

int main(){
    freopen("data.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    fgetc(stdin);
    fgets(s,100001,stdin);
    int a=0;
    for(int i=k-1;i>=0;i--){
        if(s[i]>='A'&&s[i]<='Z'){
            a++;
        }
        else
            break;
    }
    if(a%2==0){
        if(s[k]>='A'&&s[k]<='Z')
            printf("%c%c",s[k],s[k+1]);
        else
            printf("%c",s[k]);
    }
    else{
        printf("%c%c",s[k-1],s[k]);
    }
    return 0;
}
