#include<stdio.h>
long long int inline scan()
{
    long long int N = 0;
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
long long int power(long long int base,long long int exp,long long int mod)
{
    long long int result=1;
    while(exp>0)
    {
        if(exp%2==1)
            result=(result*base) % mod;
        exp=exp>>1;
        base=(base*base)%mod;
        //printf("%lld\n",result);

    }
    return result;


}
int main()
{
    int t;
    long long int n,m,ans,ans1,ans2;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        ans1=power(2,n,m);
        //printf("%lld\n",ans1);
        ans2=n%m;
        //printf("%lld\n",ans2);
        ans=(ans1+ans2- 1%m)%m;
        printf("%lld\n",ans);
        //temp=(1ll<<62)%100000000;

    }
    return 0;
}
