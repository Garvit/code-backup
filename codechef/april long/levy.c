#include<stdio.h>
#include<stdbool.h>
#define MAX 10000

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
bool pr[MAX+1];
int primes[MAX+1];
int nprime;
void sieve()
{
    nprime=0;
    primes[nprime++]=2;
    primes[nprime++]=3;
    int start=3,i;

    while(1)
    {
        for(i=start*start;i<=MAX;i+=(2*start))
        {
            pr[i]=1;
        }
        start+=2;
        for(i=start;i<=MAX;i+=2)
        {
            if(pr[i]==0)
            {
                primes[nprime++]=i;
                break;
            }
        }
        if(i>MAX)
            break;
        start=i;
    }
}
int mem[MAX+1];
int main()
{
    sieve();
    int i,j,t,n;
    for(i=0;i<nprime;i++)
    {
        for(j=0;j<nprime;j++)
        {
            if(primes[i]+2*primes[j]>10000)
                break;

            mem[primes[i]+2*primes[j]]++;

        }

    }
    t=scan();
    while(t--)
    {
        n=scan();
        printf("%d\n",mem[n]);
    }
    return 0;
}
