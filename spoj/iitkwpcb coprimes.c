#include<stdio.h>
#define ll long long

ll inline scan()
{
    ll N = 0;
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
    ll t,n,ans;
    t=scan();
    while(t--)
    {
        n=scan();
        if(n&1)
            ans=n/2;
        else
        {
            n=n/2;
            if(n&1)
                ans=n-2;
            else
                ans=n-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
