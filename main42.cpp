#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

/**
排成一条线的纸牌博弈问题
https://www.nowcoder.com/practice/19c98d950b3347d19f991d10bde12288?tpId=101&tqId=33159&tPage=2&rp=2&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int** dp1=(int**)malloc(sizeof(int*)*n);
    int** dp2=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
        dp1[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        dp2[i]=(int*)malloc(sizeof(int)*n);
    for(int j=0; j<n; j++)
    {
        for(int i=j; i>=0; i--)
        {
            if(i==j){
                dp1[i][i]=arr[i];
                dp2[i][i]=0;
            }
            else{
                dp1[i][j]=max(arr[i]+dp2[i+1][j],arr[j]+dp2[i][j-1]);
                dp2[i][j]=min(dp1[i][j-1],dp1[i+1][j]);
            }
        }
    }
    printf("%d\n",max(dp1[0][n-1],dp2[0][n-1]));
    return 0;
}
