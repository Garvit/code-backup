#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<vector>

using namespace std;

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
bool pr[10000001];
vector<int> primes[10000001];

void seive()
{
    long long i,j;
    for(i=3;i<=3163;i+=2)
    {
        if(pr[i]==0)
        {
            for(j=i*i;j<=10000000;j+=i)
            {
                pr[j]=1;
                primes[j].push_back(i);
            }
        }
    }
    //printf("%d",count);
}
int main()
{
    int n,i;
    seive();
    /*n=scan();
    while(n!=-1)
    {
        printf("1");
        for(i=0;i<primes[n].size();i++)
        {
            int p=primes[n][i];
            while(n%p==0)
            {
                printf(" x %d",p);
                n=n/p;
            }
        }
        if(n>1) printf(" x %d",n);
        printf("\n");
        n=scan();
    }*/
    return 0;
}

