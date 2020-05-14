#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    string s;
    cin>>s;
    int i=0;
    int pos=1;
    if(s[0]=='-')
    {
        i++;
        pos=-1;
    }
    int j=i;
    while(s[j]=='0')
    {
        j++;
    }
    if(j!=i)
    {
        printf("0\n");
        return 0;
    }
    int sum=0;
    int n=s.size();
    for(j=i; j<n; j++)
    {
        if(s[j]<='9'&&s[j]>='0')
        {
            sum=sum*10+(s[j]-'0')*pos;
            if((sum<=0&&pos==1)||(sum>=0&&pos==-1))
            {
                printf("0\n");
                return 0;
            }
        }
        else
        {
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n",sum);
    return 0;
}
