#include<stdio.h>
#include<string.h>
#define MOD 1000000007L

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
int power(int base,int exp,int mod)
{
    int result=1;
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
    int t,upper,d,n,m,i,j,k;
    long long ans=0;
    t=scan();
    while(t--)
    {
        upper=scan();
        d=scan();
        m=scan();
        n=scan();
        int arr[50];
        int limit=(upper<n?upper:n-1);
        long long a,b,c;
        ans=0;
        for(i=0;i<=limit;i++)
        {
            arr[i]=power(i,d,n);
        }
        for(i=0;i<=limit;i++)
        {
            for(j=0;j<=limit;j++)
            {
                for(k=0;k<=limit;k++)
                {
                    if((arr[i]+arr[j]+arr[k])%n == m)
                    {
                        a=upper/n + (i<=(upper%n));
                        b=upper/n + (j<=(upper%n));
                        c=upper/n + (k<=(upper%n));
                        long long t=((a%MOD)*(b%MOD))%MOD;
                        t=(t*(c%MOD))%MOD;
                        ans=(ans+t)%MOD;
                    }

                }
            }
        }
        printf("%lld\n",ans);

    }
    return 0;
}
