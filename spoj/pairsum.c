#include<stdio.h>
#define ull unsigned long long
#define getchar getchar_unlocked
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
int arr[100000];
ull sum[100001];
ull pairsum[100001];
int main()
{
    int n,m,i,u,v;
    ull ans=0;
    n=scan();
    arr[0]=scan();
    sum[0]=arr[0];
    pairsum[0]=arr[0]*sum[0];
    for(i=1;i<n;i++)
    {
        arr[i]=scan();
        sum[i]=sum[i-1]+arr[i];
        pairsum[i]=pairsum[i-1]+arr[i]*sum[i];
    }
    /*for(i=0;i<n;i++)
    {
        printf("%lld %lld\n",sum[i],pairsum[i]);
    }*/
    m=scan();
    while(m--)
    {
        ans=0;
        u=scan();
        v=scan();

        if(u==0) ans=pairsum[v];
        else ans=(pairsum[v]-pairsum[u-1])-(sum[u-1]*(sum[v]-sum[u-1]));

        printf("%llu\n",ans);

    }
    return 0;
}
