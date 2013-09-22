#include<stdio.h>

long long power(long long n)
{
    if(n==1)
        return 3;

    long long a=power(n/2);
    if(n%2==0)
    {
        return (a*a)%(1000000000+7);
    }
    else
    {
        return (a*a*3)%(1000000000+7);
    }
}
int main()
{
    int t,i;
    long long n,ans;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lld",&n);
        ans=power(n);
        if(n%2==0)
            ans+=3;
        else
            ans-=3;

        ans=ans%(1000000000+7);
        printf("%lld\n",ans);

    }
    return 0;
}
