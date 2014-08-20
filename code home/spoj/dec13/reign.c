#include<stdio.h>

int arr[100000];
long long front[100000];
long long back[100000];

long long max(long long a,long long b)
{
    return a>b?a:b;
}
int main()
{
    int t,n,k,i;
    long long ans=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        long long far=arr[0],curr=arr[0];
        front[0]=far;
        //printf("%lld\n",front[0]);
        for(i=1;i<n;i++)
        {
            curr=max(arr[i],curr+arr[i]);
            far=max(far,curr);
            front[i]=far;
            //printf("%lld\n",front[i]);
        }

        far=arr[n-1],curr=arr[n-1];
        back[n-1]=far;
        //printf("%lld\n",back[n-1]);
        for(i=n-2;i>=0;i--)
        {
            curr=max(arr[i],curr+arr[i]);
            far=max(far,curr);
            back[i]=far;
            //printf("%lld\n",back[i]);
        }
        ans=front[0]+back[k+1];
        for(i=k+1;i<n-1;i++)
        {
            curr=front[i-k]+back[i+1];
            ans=max(ans,curr);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
