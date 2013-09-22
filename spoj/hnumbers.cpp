#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<string.h>
#define MAX 100000

using namespace std;
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
vector<int> primes[MAX+1];
bool pr[MAX+1];
void sieve()
{
    /*for(int i=2;i<=MAX;i++)
    {
        if(primes[i].empty())
        {
            for(int j=1;j*i<=MAX;j++)
            {
                primes[j*i].push_back(i);
            }
        }
    }*/
    int start=2,i;
    while(1)
    {
        for(i=start*2;i<=MAX;i+=start)
        {
            pr[i]=1;
            primes[i].push_back(start);

        }
        start++;
        for(i=start;i<=MAX;i++)
        {
            if(pr[i]==0)
            {
                break;
            }
        }
        if(i>MAX)
            break;
        start=i;
    }
}
int n,m,t;
int eval(int i=0,int j=0,int p=1)
{
    int sign=j%2,t1,t2=0;
    if(i<primes[n].size())
    {
        t1=sign==0?primes[n][i]:-primes[n][i];
        t1=p*t1;
        t2+=m/t1;
        t2+=eval(i+1,j+1,primes[n][i]*p);
        t2+=eval(i+1,j,p);
    }
    return t2;
}
int main()
{
    sieve();
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        int ans=0;

        if(pr[n]!=0) ans=eval();

        printf("%d\n",m-ans);

    }
    return 0;
}


