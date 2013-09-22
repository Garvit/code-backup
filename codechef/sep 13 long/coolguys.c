#include<stdio.h>
#define ll long long

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ll den=n*1ll*n,num=0,g;
        for(i=1;i<=n;)
        {
            int val=n/i;
            int next=n/val+1;
            num+=val*(next-i);
            i=next;
        }
        g=gcd(den,num);
        printf("%lld/%lld\n",num/g,den/g);
    }
    return 0;
}
