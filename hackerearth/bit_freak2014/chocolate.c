#include<stdio.h>
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
    int t,n,m,s;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        s=scan();
        m=m%n;
        int ans=((long long)s-1+m)%n;
        if(ans==0) ans=n;
        printf("%d\n",ans);
    }
    return 0;
}
