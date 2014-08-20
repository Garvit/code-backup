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
        for(i=0;i<count;i++)
        {
            p=primes[i];
            if(p>r) break;
            ll start=l/p;
            if(l!=start*p) start++;
            //printf("%d %lld\n",p,start);
            while(p*start<=r)
            {
                if(arr[p*start-l]==0) arr[p*start-l]=p;
                else if(arr[p*start-l]!=-1) arr[p*start-l]=-1;

                start++;
            }
        }
        int d=r-l,ans=0,cp=0;
        ll q;
        for(i=0;i<=d;i++)
        {
            //printf("%d\n",arr[i]);
            if(arr[i]==0) cp++;
            else if(arr[i]!=-1)
            {
                p=arr[i];
                ll n=l+i,c=1;
                //q=log(n)/log(p);
                //if(pow(p,q)==n) ans++;
                while(n>1)
                {
                    c++;
                    q=n/p;
                    if(q*p!=n){c=0;break;}
                    n=q;
                }
                //printf("n: %lld c: %d\n",l+i,c);
                if((c==2) || (c%2!=0 && pr[c]==0)) ans++;
            }
        }
        if(l==1) ans--;
        ans+=cp;
        printf("%d\n",ans);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
