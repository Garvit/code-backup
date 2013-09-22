#include<stdio.h>

int main()
{
    int t,u,n,m,c,i,ans;
    float d,r,best,cur;
    scanf("%d",&t);
    while(t--)
    {
        best=0;
        ans=0;
        scanf("%f%d%d",&d,&u,&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d %f %d",&m,&r,&c);
            cur=u*(d-r)-c*1.0/m;
            //printf("%f\n",cur);
            if(cur>best)
            {
                best=cur;
                ans=i;
            }
        }
        if(best==0)
            printf("0\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
