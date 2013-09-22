#include<stdio.h>
#include<stdbool.h>
#include<string.h>
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
bool pr[10001];
void sieve()
{
    int start=3,i;

    while(1)
    {
        for(i=3*start;i<10000;i+=(2*start))
        {
            pr[i]=1;
            //printf("%d ",i);
        }
        start+=2;
        for(i=start;i<10000;i+=2)
        {
            if(pr[i]==0)
            {
                break;
            }
        }
        if(i>=32000)
            break;
        start=i;
    }
}

int main()
{
    int n;
    n=scan();
    sieve();
    int num=n,count=0,i;

    while(num>0)
    {
        count+=num/2;
        num=num/2;
    }
    printf("2^%d",count);

    for(i=3;i<=n;i+=2)
    {
        if(pr[i]==0)
        {
            num=n;count=0;
            while(num>0)
            {
                count+=num/i;
                num=num/i;
            }
            printf(" * %d^%d",i,count);
        }
    }
    return 0;
}
