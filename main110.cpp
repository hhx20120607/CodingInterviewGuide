#include<stdio.h>
#include<map>

typedef struct
{
    int val;
    int time;
} rcd;

int next=0;
std::map<int,rcd> map1;

rcd* t=NULL;

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int o;
        scanf("%d",&o);
        int key,val;;
        switch(o)
        {
        case 1:
            scanf("%d%d",&key,&val);
            map1[key]= {val,next++};
            break;
        case 2:
            scanf("%d",&key);
            if(map1.find(key)!=map1.end()){
                if(t&&t->time>map1[key].time)
                    printf("%d\n",t->val);
                else
                    printf("%d\n",map1[key].val);
            }
            else
                printf("-1\n");
            break;
        case 3:
            if(!t)
                t=(rcd*)malloc(sizeof(rcd));
            scanf("%d",&val);
            t->time=next++;
            t->val=val;
            break;
        default:
            break;
        }
    }
    return 0;
}
