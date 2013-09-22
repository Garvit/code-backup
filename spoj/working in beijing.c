#include<stdio.h>
#include<stdbool.h>
#define getchar getchar_unlocked
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

int time[100000];
int main()
{
    int n,a,b,i,t,z;
    long long ans;
    t=scan();
    for(z=1;z<=t;z++)
    {
        ans=0;
        n=scan();
        a=scan();
        b=scan();
        for(i=0;i<n;i++)
        {
            time[i]=scan();
        }
        ans+=a+b;
        for(i=0;i<n-1;i++)
        {
            if((time[i+1]-time[i]-1)*b-2*a> 0)
            {
                ans+=2*a+b;
            }
            else
            {
                ans+=(time[i+1]-time[i])*b;
            }
            //printf("%lld\n",ans);
        }
        ans+=a;
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}
