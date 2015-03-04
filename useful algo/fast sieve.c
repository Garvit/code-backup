#include <stdio.h>
#include <string.h>
#define ULL unsigned long long
#define MAX 1000000
#define limit 1000

#define check(n) (pr[n>>6]&(1<<((n>>1)&31)))
#define set(n) (pr[n>>6]|=(1<<((n>>1)&31)))

unsigned pr[MAX/64];
unsigned primes[664580];
int count=0;
void sieve()
{
    ULL i,j;
    primes[count++]=2;
    for(i=3;i<=limit;i+=2)
    {
        if(!check(i))
        {
            //printf("%d,",i);
            for(j=i*i;j<=MAX;j+=2*i)
            {
                set(j);
            }
        }
    }
    for(i=3;i<=MAX;i+=2)
    {
        if(!check(i)) primes[count++]=i;
    }
    printf("%d",count);
}
