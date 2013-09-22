#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define getcx getchar_unlocked
#define MAX 10000000

inline void inp( int *n )
{
    *n=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' )
        ch=getcx();
    while(  ch >= '0' && ch <= '9' )
        *n = (*n<<3)+(*n<<1) + ch-'0', ch=getcx();
}

typedef 
struct server
{
    int pass, isHacked;
} server;

bool arr[MAX];
int mem[MAX];

int isPrime(int n)
{
    if(n==1)
        return 0;
    else if(n%2==0)
        return 0;
    else
        return arr[n]==0;
}

void sieve()
{
    int i=0,start, count;
    start=3, count=1;
    mem[3]=1;
    while(1)
    { 
        for(i=3*start; i<MAX; i+=(2*start))
        {
            arr[i]=1;
        }
        start+=2;
        for(i=start; i<MAX; i+=2)
        {
            if(arr[i]==0)
            {
                mem[i]=++count;
                break;
            }
        }
        if(i>=MAX)
            break;
        start=i;
    }
}

void hackodd(server **comp, int i, int j, int N)
{
    if(i-1>=0 && comp[i-1][j].isHacked==0 && comp[i-1][j].pass%2==1 && isPrime(comp[i-1][j].pass)==0)
    {
        comp[i-1][j].isHacked=1;
        hackodd(comp,i-1,j,N);
    }
    if(j-1>=0 && comp[i][j-1].isHacked==0 && comp[i][j-1].pass%2==1 && isPrime(comp[i][j-1].pass)==0)
    {
        comp[i][j-1].isHacked=1;
        hackodd(comp,i,j-1,N);
    }
    if(i+1<N && comp[i+1][j].isHacked==0 && comp[i+1][j].pass%2==1 && isPrime(comp[i+1][j].pass)==0)
    {
        comp[i+1][j].isHacked=1;
        hackodd(comp,i+1,j,N);
    }
    if(j+1<N && comp[i][j+1].isHacked==0 && comp[i][j+1].pass%2==1 && isPrime(comp[i][j+1].pass)==0)
    {
        comp[i][j+1].isHacked=1;
        hackodd(comp,i,j+1,N);
    }
    return;
}

void hackeven(server **comp, int i, int j, int N)
{
    if(i-1>=0 && comp[i-1][j].isHacked==0 && comp[i-1][j].pass%2==0 && comp[i-1][j].pass!=2)
    {
        comp[i-1][j].isHacked=1;
        hackeven(comp,i-1,j,N);
    }
    if(j-1>=0 && comp[i][j-1].isHacked==0 && comp[i][j-1].pass%2==0 && comp[i][j-1].pass!=2)
    {
        comp[i][j-1].isHacked=1;
        hackeven(comp,i,j-1,N);
    }
    if(i+1<N && comp[i+1][j].isHacked==0 && comp[i+1][j].pass%2==0 && comp[i+1][j].pass!=2)
    {
        comp[i+1][j].isHacked=1;
        hackeven(comp,i+1,j,N);
    }
    if(j+1<N && comp[i][j+1].isHacked==0 && comp[i][j+1].pass%2==0 && comp[i][j+1].pass!=2)
    {
        comp[i][j+1].isHacked=1;
        hackeven(comp,i,j+1,N);
    }
    return;
}

int num_misses(server **comp, int i, int j, int N)
{
    int ret=0, pass=comp[i][j].pass;

    if(comp[i][j].isHacked==1 || pass==2)
        return 0;

    if(pass%2==0)
    {
        ret = pass/2;
        comp[i][j].isHacked=1;
        hackeven(comp, i, j, N);
    }
    else if(isPrime(pass)==1)
    {
        comp[i][j].isHacked=1;
        return mem[pass];
    }
    else
    {
        ret = (pass+3)/2;
        comp[i][j].isHacked=1;
        hackodd(comp, i, j, N);
    }
    return ret;
}

int main()
{
    int T=0,N,i,j,temp;
    long long ans;
    server **comps;
    inp(&T);

    sieve();
    while(T--)
    {
        N=0,i=0,j=0,ans=0;
        inp(&N);

        comps = (server**) malloc(N*sizeof(server*));
        for(i=0; i<N; i++)
        {
            comps[i] = (server*) malloc(N*sizeof(server));
            for(j=0; j<N; j++)
            {
                inp(&(comps[i][j].pass));
                comps[i][j].isHacked = 0;
            }
        }

        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                temp = num_misses(comps,i,j,N);
                ans += temp;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
