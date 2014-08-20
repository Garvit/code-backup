#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#define ll long long

ll inline scan()
{
    ll N = 0;
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
bool pr[1000001];
int primes[80000];
int count=0;
void seive()
{
    primes[count++]=2;
    ll i,j;
    pr[1]=1;
    for(i=3;i<=1000000;i+=2)
    {
        if(pr[i]==0)
        {
            primes[count++]=i;
            for(j=i*i;j<=1000000;j+=i)
                pr[j]=1;
        }
    }
    //printf("%d",count);
}
int arr[1000001];
int main()
{
    seive();
    int t,i,p;
    ll l,r;
    t=scan();
    while(t--)
    {
        l=scan();
        r=scan();
        int ans=0;
        for(i=0;i<count;i++)
        {
            p=primes[i];
            if(p>r) break;
            int start=log(l)/log(p);
            ll raise=pow(p,start);
            //printf("%lld %d\n",raise,start);
            if(l!=raise){ start++; raise=raise*p;}
            //printf("%d %lld\n",p,start);
            //printf("%lld %d\n",raise,start);
            while(raise<=r)
            {
                printf("%lld %d\n",raise,start+1);
                int s=start+1;
                if((s==2) || (s%2!=0 && pr[s]==0)) ans++;
                raise=raise*p;
                start++;
            }
        }
        printf("%d\n",ans);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}

