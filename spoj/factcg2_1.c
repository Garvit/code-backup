#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>

int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    if(C==EOF) return -1;
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}
void print_int(int p)
{
    if(p/10 != 0)
        print_int(p/10);
    putchar(48+p%10);
}
void printhelp(int p)
{
    putchar(' ');
    putchar('x');
    putchar(' ');
    print_int(p);

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
    int n,i;
    seive();
    n=scan();
    while(n!=-1)
    {
        putchar('1');
        while(n%2==0)
        {
            printhelp(2);
            n=n>>1;
        }
        while(primes[n]!=0)
        {
            short int p=primes[n];
            while(n%p==0)
            {
                printhelp(p);
                n=n/p;
            }
        }
        if(n>1) printhelp(n);
        putchar('\n');
        n=scan();
    }
    return 0;
}

