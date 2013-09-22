#include<stdio.h>
#define MOD 1000000007
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

int main()
{
    long long int t,num,ans;
    t=scan();
    while(t--)
    {
        num=scan();
        long long int m=MOD*24ll;
        //ans=((((num*(num-1))%m)*(((num-2)*(num-3))%m))%m)/24;
        ans=(((num*(num-1))%m *(num-2))%m * (num-3))%m;
        ans/=24;
        printf("%lld\n",ans);
    }
    return 0;
}
