#include<stdio.h>
#include<stdbool.h>

bool pr[20];
int team[20];
int main()
{
    int t,n,p,z,i,ans,j;
    scanf("%d",&t);
    for(z=1;z<=t;z++)
    {
        ans=0;
        scanf("%d %d",&n,&p);
        for(i=0;i<n;i++)
        {
            team[i]=0;
            for(j=0;j<p;j++)
            {
                int v;
                scanf("%d",&v);
                team[i]+=v;
                pr[j]=pr[j]|v;

            }
        }
        for(i=0;i<p;i++)
        {
            if(pr[i]==0)
            {
                break;
            }
        }
        if(i==p) ans+=4;

        for(i=0;i<n;i++)
        {
            if(team[i]==0)
                break;
        }
        if(i==n) ans+=2;

        for(i=0;i<n;i++)
        {
            if(team[i]==p)
                break;
        }
        if(i==n) ans+=1;

        printf("Case %d: %d\n",z,ans);
        memset(pr,0,sizeof(pr));
    }
}
