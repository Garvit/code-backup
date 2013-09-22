#include<stdio.h>

long long inline scan()
{
    long long  N = 0;
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

void eval(long long x)
{
    if(x==1){ printf("1"); return; }

    if(x==3) {printf("2"); return; }

    if(((x+1)/2)%2==1)
    {
        eval((x+1)/2);
        printf("1");
    }
    else
    {
        eval((x-1)/2);
        printf("2");
    }

}
int main()
{
    int t,k;
    long long x;
    scanf("%d",&t);
    while(t--)
    {
        x=scan();
        if(x%2==0)
        {
            printf("0\n");
        }
        else
        {
            eval(x);
            printf("\n");
        }
    }
    return 0;
}
