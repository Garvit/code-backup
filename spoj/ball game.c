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
    int t,n,x;
    double num,ans;
    t=scan();
    while(t--)
    {
        n=scan();
        num=(n+1);
        ans=1.0-1.0/num;
        printf("%.8f\n",ans);
    }
    return 0;

}
