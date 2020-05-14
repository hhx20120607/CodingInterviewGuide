#include<stdio.h>
#include<string.h>
#include<limits.h>
#define maxn 100002

char s1[maxn];
char s2[maxn];
int hash[256];

int main()
{
    freopen("data.in","r",stdin);
    scanf("%s",s1);
    scanf("%s",s2);
    int n1=strlen(s1);
    int n2=strlen(s2);
    for(int i=0; i<n2; i++)
        hash[s2[i]]--;
    int sum=-n2;
    int ans=INT_MAX;
    int i=0,j=0;
    while(j<n1)
    {
        hash[s1[j]]++;
        if(hash[s1[j]]<=0)
            sum++;
        if(sum==0)
        {
            while(hash[s1[i]]>0)
            {
                hash[s1[i]]--;
                i++;
            }
            if(j-i+1<ans)
                ans=j-i+1;
            sum--;
            hash[s1[i]]--;
            i++;
        }
        j++;
    }
    if(ans==INT_MAX)
        printf("0\n");
    else
        printf("%d\n",ans);
    return 0;
}
