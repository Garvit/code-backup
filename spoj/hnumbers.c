#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 100000
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
bool pr[MAX];
int primes[MAX],nprimes=0;

void sieve()
{
    int start=3,i,limit=ceil(sqrt(MAX));
    primes[nprimes++]=2;
    primes[nprimes++]=3;
    while(1)
    {
        for(i=start*3;i<MAX;i+=(2*start))
        {
            pr[i]=1;

        }
        start+=2;
        for(i=start;i<MAX;i+=2)
        {
            if(pr[i]==0)
            {
                primes[nprimes++]=i;
                break;
            }
        }
        if(i>MAX)
            break;
        start=i;
    }
}
int arr[MAX][2];
int eval(int start,int end,int m)
{
    int i,ans=0;
    for(i=start;i<=end;i++)
    {
        if(arr[i][1]%2==0)
        {
            ans+=m/arr[i][0];
        }
        else
            ans-=m/arr[i][0];
    }
    return ans;
}
int main()
{
    int i,t,n,m,k,j,prev,num;
    sieve();
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        k=0;
        int ans=0,j;
        if(m==1 || (n%2!=0 && pr[n]==0))
        {
            ans=m;
            //printf("in");
        }
        else
        {
            num=n;
            for(i=0;i<nprimes && primes[i]<=m;i++)
            {
                if(num%2!=0 && pr[num]==0 && num<=m)
                {
                    prev=k;
                    arr[k][0]=num;
                    arr[k][1]=1;
                    k++;
                    for(j=0;j<prev;j++)
                    {
                        if(arr[j][0]*num<=m){
                        arr[k][0]=arr[j][0]*num;
                        arr[k][1]=arr[j][1]+1;
                        k++;}
                    }
                    break;
                }
                if(n%primes[i]==0)
                {
                    while(num%primes[i]==0)
                    {
                        num=num/primes[i];
                    }

                    prev=k;
                    arr[k][0]=primes[i];
                    arr[k][1]=1;
                    k++;
                    for(j=0;j<prev;j++)
                    {
                        if(arr[j][0]*primes[i]<=m){
                        arr[k][0]=arr[j][0]*primes[i];
                        arr[k][1]=arr[j][1]+1;
                        k++;}
                    }
                    if(num==1)
                         break;
                }
            }
            ans=m+eval(0,k-1,m);

        }
        printf("%d\n",ans);
        memset(arr,0,sizeof(arr));

    }
    return 0;
}

