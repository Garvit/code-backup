#include<stdio.h>
#include<stdbool.h>
int *value;

double poss(int start,int end,bool b)        //b=true for alice    and false for bob
{
    double x,y;
    if(b)
    {
        if(start==end)
            return value[start];
        else
        {
            x=value[start]+poss(start+1,end,false);
            y=value[end]+poss(start,end-1,false);

        }
    }
    else
    {
        if(start==end)
            return 0;
        else
        {
            x=poss(start+1,end,true);
            y=poss(start,end-1,true);
        }
    }
    return (x+y)/2;
}
int main()
{
    int t,n,i,j;
    double ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        value=calloc(n,sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&value[j]);
        }
        ans=poss(0,n-1,true);
        printf("%.3f\n",ans);

    }
    return 0;
}
