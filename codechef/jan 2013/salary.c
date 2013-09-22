#include<stdio.h>
int w[100];
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
    int t,n,max,i,ans,min,p1,p2;
    t=scan();
    while(t--)
    {
        n=scan();
        max=0;

        min=10000;
        ans=0;
        for(i=0;i<n;i++)
        {
            w[i]=scan();
            if(max<=w[i])
            {
                max=w[i];
                p1=i;
            }
            if(min>=w[i])
            {
                min=w[i];
                p2=i;
            }

        }
        ans+=max-min;
        for(i=0;i<n;i++)
        {
            if(i!=p1 && i!=p2)
                ans+=(w[i]-min);
        }
        printf("%d\n",ans);

    }
    return 0;
}
