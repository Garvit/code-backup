#include<stdio.h>
#define ll long long
#define MOD 1000000007
ll func(ll n)
{
    if(n<0) return 0;
    ll sum=(n+1)*(n+2)/2;
    return sum;
}

int main()
{
    int t,i,j;
    ll mina,maxa,minb,maxb,minc,maxc,ans,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        scanf("%lld %lld",&mina,&maxa);
        scanf("%lld %lld",&minb,&maxb);
        scanf("%lld %lld",&minc,&maxc);
        n-=(mina+minb+minc);
        ll a=maxa-mina+1;
        ll b=maxb-minb+1;
        ll c=maxc-minc+1;
        ans=func(n)-func(n-a)-func(n-b)-func(n-c)+func(n-a-b)+func(n-b-c)+func(n-c-a)-func(n-a-b-c);
        ans=ans%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
