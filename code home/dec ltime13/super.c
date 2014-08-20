#include<stdio.h>

int m;
long long pow(long long base,int exp)
{
    long long result=1;
    while(exp>0)
    {
        if(exp&1) result=(result*base)%m;
        base=(base*base)%m;
        exp=exp>>1;
    }
    return result;
}
long long gcd(long long a,long long b)
{
    long long r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}
int main()
{
    long long n,i,ans=0;
    int k;
    scanf("%lld %d %d",&n,&k,&m);
    for(i=1;i<n;i++)
    {
        if(gcd(n,i)==1)
        {
            ans=(ans+pow(i,k)%m)%m;
        }
    }
    printf("%lld",ans);
    return 0;
}
