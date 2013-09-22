#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

bool serverhack[350][350];
int serverpass[350][350];

bool pr[10000000];
int mem[10000000];

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
void sieve()
{
    int count=1,start=3,i;
    mem[3]=1;
    while(1)
    {
        for(i=3*start;i<10000000;i+=(2*start))
        {
            pr[i]=1;
        }
        start+=2;
        for(i=start;i<10000000;i+=2)
        {
            if(pr[i]==0)
            {
                count++;
                mem[i]=count;
                break;
            }
        }
        if(i>=10000000)
            break;
        start=i;
    }
}
bool isprime(int p)
{
    if(p==1)
    {
        return false;
    }
    if(p==2)
    {
        return true;
    }
    if(p%2==0)
        return false;
    if(pr[p]==0)
    {
        return true;
    }
}
void even(int i,int j,int n)
{
    if(i>0 && !serverhack[i-1][j] && !isprime(serverpass[i-1][j]) && serverpass[i-1][j]%2==0)
    {
        serverhack[i-1][j]=1;
        even(i-1,j,n);
    }
    if(j>0 && !serverhack[i][j-1] && !isprime(serverpass[i][j-1]) && serverpass[i][j-1]%2==0)
    {
        serverhack[i][j-1]=1;
        even(i,j-1,n);
    }
    if(i<n-1 && !serverhack[i+1][j] && !isprime(serverpass[i+1][j]) && serverpass[i+1][j]%2==0)
    {
        serverhack[i+1][j]=1;
        even(i+1,j,n);
    }
    if(j<n-1 && !serverhack[i][j+1] && !isprime(serverpass[i][j+1]) && serverpass[i][j+1]%2==0)
    {
        serverhack[i][j+1]=1;
        even(i,j+1,n);
    }
}

void odd(int i,int j,int n)
{
    if(i>0 && !serverhack[i-1][j] && !isprime(serverpass[i-1][j]) && serverpass[i-1][j]%2!=0)
    {
        serverhack[i-1][j]=1;
        odd(i-1,j,n);
    }
    if(j>0 && !serverhack[i][j-1] && !isprime(serverpass[i][j-1]) && serverpass[i][j-1]%2!=0)
    {
        serverhack[i][j-1]=1;
        odd(i,j-1,n);
    }
    if(i<n-1 && !serverhack[i+1][j] && !isprime(serverpass[i+1][j]) && serverpass[i+1][j]%2!=0)
    {
        serverhack[i+1][j]=1;
        odd(i+1,j,n);
    }
    if(j<n-1 && !serverhack[i][j+1] && !isprime(serverpass[i][j+1]) && serverpass[i][j+1]%2!=0)
    {
        serverhack[i][j+1]=1;
        odd(i,j+1,n);
    }
}
int main()
{
    int t,n,i,j,temp;
    long long ans=0;
    sieve();
    t=scan();
    while(t--)
    {
        n=scan();
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                serverpass[i][j]=scan();
                serverhack[i][j]=false;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(!serverhack[i][j]){
                if(isprime(serverpass[i][j]))
                {
                    ans+=mem[serverpass[i][j]];
                    serverhack[i][j]=true;
                    //printf("%lld\n",ans);
                }
                else if(serverpass[i][j]%2==0)
                {
                    ans+=(serverpass[i][j]/2);
                    //printf("%lld\n",ans);
                    serverhack[i][j]=true;
                    even(i,j,n);
                }
                else
                {
                    ans+=(serverpass[i][j]+3)/2;
                    //printf("%lld\n",ans);
                    serverhack[i][j]=true;
                    odd(i,j,n);
                }

                }
            }
        }

        printf("%lld\n",ans);

    }
    return 0;
}
