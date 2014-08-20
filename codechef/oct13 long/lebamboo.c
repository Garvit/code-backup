//if possible steps (ans)=(sum(D)-sum(H))/(n-2)
//for each stem: D-H=ans-2*m;  if m int in all then ok
#include<stdio.h>

int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}
int main()
{
    short int h[50],d[50];
    short int t,n,i;
    t=scan();
    while(t--)
    {
        n=scan();
        short int sumh=0,sumd=0,ans=0;
        for(i=0;i<n;i++)
        {
            h[i]=scan();
            sumh+=h[i];
        }
        for(i=0;i<n;i++)
        {
            d[i]=scan();
            sumd+=d[i];
        }
        if(n==1)
        {
            if(d[0]>h[0]) ans=-1;
            else ans=h[0]-d[0];
        }
        else if(n==2)
        {
            if(sumh!=sumd) ans=-1;
            else
            {
                ans=(d[0]>h[0])?(d[0]-h[0]):(h[0]-d[0]);
            }
        }
        else
        {
            if((sumd-sumh)%(n-2)!=0) ans=-1;
            else
            {
                ans=(sumd-sumh)/(n-2);
                for(i=0;i<n;i++)
                {
                    short int num=ans-(d[i]-h[i]);
                    if(num<0 || num&1)
                    {
                        ans=-1;
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
