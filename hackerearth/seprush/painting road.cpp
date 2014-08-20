#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
typedef struct prop
{
    int a,b,c;
    prop(int x,int y,int z)
    {
        a=x;b=y;c=z;
    }
}prop;
bool compare(prop* a,prop* b)
{
    return a->b<b->b;
}
prop* arr[520];
int cost[260];
int main()
{
    int t,l,k,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&l,&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            arr[i]=new prop(a,b,c);
        }
        sort(arr,arr+k,compare);
        int limit=0,minc;
        for(int i=0;i<k;i++)
        {
            if(arr[i]->a<=limit)
            {
                minc=cost[limit]+arr[i]->c;
                for(int j=limit-1;j>=0;j--)
                {
                    if(arr[i]->a >j) break;
                    //printf("%d %d\n",minc,cost[j]);
                    if((cost[j]!=0 || j==0) && (cost[j]+arr[i]->c)<minc)
                    {
                        minc=cost[j]+arr[i]->c;
                    }
                }
                if(cost[arr[i]->b]==0 || cost[arr[i]->b]>minc)
                    cost[arr[i]->b]=minc;
                limit=arr[i]->b;
            }
        }
        /*for(int i=1;i<=l;i++)
        {
            printf("%d ",cost[i]);
        }*/
        if(cost[l]!=0) printf("%d\n",cost[l]);
        else printf("-1\n");

        memset(cost,0,sizeof(cost));
    }
    return 0;
}
