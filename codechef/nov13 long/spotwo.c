#include<stdio.h>
#define MOD 1000000007
#define ll long long
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
ll power(ll base,ll exp)
{
    ll result=1;

    while(exp>0)
    {
        if(exp&1)
            result=(result*base) % MOD;
        exp=exp>>1;
        base=(base*base)%MOD;

    }
    return result;


}
int arr[21];
void precompute()
{
    arr[1]=2;
    int i;
    for(i=2;i<=20;i++)
    {
        arr[i]=power(arr[i-1],10);
        //printf("%d\n",arr[i]);
    }

}
int main()
{
    precompute();
    int t,n,i;
    t=scan();
    while(t--)
    {
        n=scan();
        ll ans=1;
        int k=1;
        while(n!=1)
        {
            if(n&1){ ans=(ans*arr[k])%MOD;}
            k++;
            n/=2;
        }
        ans=(ans*arr[k])%MOD;
        ans=(ans*ans)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
