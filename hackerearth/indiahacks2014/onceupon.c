#include<stdio.h>
int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1;C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}

long long max(long long a,long long b)
{
    return a>b?a:b;
}
int arr[10000];
long long dp[10000];

int main()
{
    int t,n,k,i,flag;
    t=scan();
    while(t--)
    {
        n=scan();
        k=scan();
        flag=0;
        for(i=0;i<n;i++){
            arr[i]=scan();
            if(arr[i]>0) flag=1;
        }
        if(flag==0)
        {
            printf("0\n");
        }
        else{
        dp[n-1]=arr[n-1]>0?arr[n-1]:0;
        for(i=n-2;i>=n-1-k;i--)
            dp[i]=max(arr[i],dp[i+1]);
        for(i=n-2-k;i>=0;i--){
            dp[i]=max(arr[i]+dp[i+k+1],dp[i+1]);
        }
        printf("%lld\n",dp[0]);
        }
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
