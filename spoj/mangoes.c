#include<stdio.h>
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

int main()
{
    int t,n;
    long long ans;
    t=scan();
    while(t--)
    {
        n=scan();
        ans=(n-1)/2;
        ans=(ans*ans)%n;
        printf("%lld\n",ans);
    }
    return 0;
}
