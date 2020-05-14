#include<stdio.h>
#include<string.h>
#define maxn 301

char s1[maxn];
char s2[maxn];
int n1;
int n2;

bool match(int i,int j)
{
    if(j==n2)
        return i==n1;
    if(j==n2-1||s2[j+1]!='*')
        return i<=n1-1&&(s1[i]==s2[j]||s2[j]=='.')&&match(i+1,j+1);
    int t=i;
    while(i<=n1-1&&(s1[i]==s2[j]||s2[j]=='.'))
    {
        if(match(i+1,j+2))
            return true;
        i++;
    }
    return match(t,j+2);
}

int main()
{
    freopen("data.in","r",stdin);
    scanf("%s",s1);
    scanf("%s",s2);
    n1=strlen(s1);
    n2=strlen(s2);
    if(match(0,0))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
