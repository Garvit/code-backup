#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10000000

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
short int primes[10000001];
void seive()
{
    int i,j;
    for(i=3;i<=3163;i+=2)
    {
        if(primes[i]==0)
        {
            for(j=i*i;j<=10000000;j+=2*i)
            {
                if(primes[j]==0) primes[j]=i;
            }
        }
    }
}
int main()
{
    seive();
    int t,n,even,c,p;
    t=scan();
    while(t--)
    {
        n=scan();
        even=0;
        c=0;
        if(n%2==0){
        while(n%2==0)
        {
            c++;
            n=n>>1;
        }
        if(c%2==0) even++;
        else even--;
        }
        while(primes[n]!=0)
        {
            short int p=primes[n];
            c=0;
            while(n%p==0)
            {
                c++;
                n=n/p;
            }
            if(c%2==0) even++;
            else even--;
        }

        if(n>1) even--;
        if(even>0) printf("Psycho Number\n");
        else printf("Ordinary Number\n");

    }
    return 0;
}
