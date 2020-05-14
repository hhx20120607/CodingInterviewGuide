#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int** arr=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
        arr[i]=(int*)malloc(sizeof(int)*m);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            scanf("%d",&arr[i][j]);
    }
    int i=0,j=-1;
    int k=0,d=1,s=n*m;
    int left=0,right=m-1,up=0,down=n-1;
    while(k<s)
    {
        switch(d)
        {
        case 1:
            if(j+1<=right)
                j++;
            else
            {
                d=2;
                up++;
                continue;
            }
            break;
        case 2:
            if(i+1<=down)
                i++;
            else
            {
                d=3;
                right--;
                continue;
            }
            break;
        case 3:
            if(j-1>=left)
                j--;
            else
            {
                d=4;
                down--;
                continue;
            }
            break;
        case 4:
            if(i-1>=up)
                i--;
            else
            {
                d=1;
                left++;
                continue;
            }
            break;
        default:
            break;
        }
        printf("%d",arr[i][j]);
        k++;
        if(k!=n*m)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
