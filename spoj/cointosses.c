#include<stdio.h>
#include<math.h>
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
    int t,m,n;
    double x,y,ans;

    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();

        x=pow(2,n+1);
        y=pow(2,m+1);
        ans=x-y;
        printf("%.2lf\n",ans);
    }
    return 0;
}
