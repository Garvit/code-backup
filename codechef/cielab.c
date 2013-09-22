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
    int a,b,ans,d;
    a=scan();
    b=scan();
    ans=a-b;
    d=ans%10;
    if(d!=9)
    {
        printf("%d",ans+1);
    }
    else
    {
        printf("%d",ans-1);
    }
    return 0;
}

