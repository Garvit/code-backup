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
long long inline scan1()
{
    long long N = 0;
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

long long red[1001];
int main()
{
    int t,l,n,c,r,low,high,m,i;
    long long d,power;
    t=scan();
    while(t--)
    {
        l=scan();
        n=scan();
        while(n--)
        {
            c=scan();
            r=scan();
            d=scan1();
            low=c-r;
            low=1>low?1:low;
            high=c+r;
            high=l<high?l:high;
            for(i=low;i<=high;i++)
            {
                red[i]+=d;
            }
        }
        m=scan();
        while(m--)
        {
            power=scan1();

            for(i=1;i<=l;i++)
            {
                power-=red[i];
                if(power<=0)
                {
                    printf("%d\n",i);
                    break;
                }
            }
            if(power>0)
            {
                printf("Bloon leakage\n");
            }
        }
        memset(red,0,sizeof(red));
    }
    return 0;
}

