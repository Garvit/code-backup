#include<stdio.h>
#define MOD 1000000007

int extended_gcd(int a,int b)
{
    int x=0,y=1,lastx=1,lasty=0,q,temp;
    while(b!=0)
    {
        q=a/b;
        temp=a;
        a=b;
        b=temp%b;
        temp=x;
        x=lastx-q*x;
        lastx=temp;
        temp=y;
        y=lasty-q*y;
        lasty=temp;
        //printf("%d %d \n",x,y);
    }
    return lasty;
}
long long int power(long long int base,long long int exp)
{
    long long int result=1;
    while(exp>0)
    {
        if(exp%2==1)
            result=(result*base) % MOD;
        exp=exp>>1;
        base=(base*base)%MOD;
        //printf("%lld\n",result);

    }
    return result;
}

int main()
{
    int n,l,i;
    long long ans=0,prev;
    scanf("%d %d",&n,&l);
    while(n!=0 || l!=0)
    {
        prev=n;
        ans=0;
        for(i=1;i<=l;i++)
        {
            ans=(ans+prev)%MOD;
            prev=(prev*n)%MOD;
        }
        printf("%lld\n",ans);
        scanf("%d %d",&n,&l);
    }
    return 0;
}
