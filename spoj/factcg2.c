#include<stdio.h>
#include<stdbool.h>
#include<math.h>
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
bool pr[10000001];
int primes[1000];
int count;
void seive()
{
    long long i,j;
    count=0;
    primes[count++]=2;
    for(i=3;i<=3163;i+=2)
    {
        if(pr[i]==0)
        {
            primes[count++]=i;
            for(j=i*i;j<=10000000;j+=2*i)
            {
                pr[j]=1;
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
        for(i=0;i<count;i++)
        {
            if(n==1) break;
            if(n%2!=0 && pr[n]==0) break;
            int p=primes[i];
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
