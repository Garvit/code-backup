#include<stdio.h>
#include<math.h>

long long func(long long n)
{
    int limit=sqrt(n),i;
    long long ans=0;
    for(i=1;i<=limit;i++)
    {
        ans+=n/i-i+1;
        if(n%i==0) ans--;
    }
    ans=2*ans-limit;
    if(limit*limit==n) ans++;
    //printf("%lld %lld\n",n,ans);
    return ans;
}
int main()
{
    int t,n,i;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        for(i=1;i<n/2;i++)
        {
            ans+=func(i*(n-i));
        }
        //printf("%lld\n",ans);
        ans*=2;
        long long temp=func(n*n/4);
        if(n%2==0)
            ans+=temp;
        else ans+=2*temp;

        printf("%lld\n",ans);
    }
    return 0;
}
