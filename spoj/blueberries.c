#include<stdio.h>
#include<string.h>
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
int arr[1000];
/*int dp[1001][1001];
int eval(int i,int k,int n)
{
    if(i>=n) return 0;
    if(k<=0) return 0;
    if(dp[i][k]) return dp[i][k];
    int val1=0,val2;
    if(arr[i]<=k)
        val1=arr[i]+eval(i+2,k-arr[i],n);
    val2=eval(i+1,k,n);
    dp[i][k]=(val1<val2)?val2:val1;
    return dp[i][k];
}*/
int main()
{
    int t,n,k,z,i,ans,inc,exc,temp;
    t=scan();
    for(z=1;z<=t;z++)
    {
        n=scan();
        k=scan();
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        inc=arr[0]<=k?arr[0]:0;
        exc=0;
        for(i=1;i<n;i++)
        {
            temp=inc>exc?inc:exc;
            inc=(exc+arr[i])<=k?(exc+arr[i]):exc;
            exc=temp;
            printf("%d %d\n",inc,exc);
        }
        ans=inc>exc?inc:exc;
        printf("Scenario #%d: %d\n",z,ans);

    }
    return 0;
}
