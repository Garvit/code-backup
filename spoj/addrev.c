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
int rev(int x)
{
    int r=0;
    while(x>0)
    {
        r=r*10+(x%10);
        x=x/10;
    }
    return r;
}
int main()
{
    int n,a,b,sum,reva,revb,revsum;
    n=scan();
    while(n--)
    {
        a=scan();
        b=scan();
        reva=rev(a);
        revb=rev(b);
        revsum=reva+revb;
        sum=rev(revsum);
        printf("%d\n",sum);
    }
    return 0;
}
