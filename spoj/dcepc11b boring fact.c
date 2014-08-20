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
ll extended_gcd(ll a,ll b)
{
    ll x=0,lastx=1,q,temp,p=b;
    while(b!=0)
    {
        q=a/b;
        temp=a;
        a=b;
        b=temp%b;
        temp=x;
        x=(lastx-q*x)%p;
        if(x<0) x+=p;
        lastx=temp;
        //printf("%d %d \n",x,y);
    }
    return lastx;
}
int main()
{
    int t,i;
    ll n,p,ans;
    t=scan();
    while(t--)
    {
        n=scan();
        p=scan();
        if(n>=p) ans=0;
        else
        {
            if(n==p-1) ans=p-1;
            else if(n==p-2) ans=1;
            else
            {
                ans=1;
                for(i=2;i<p-n;i++)
                {
                    ans=(ans*extended_gcd(p-i,p))%p;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
