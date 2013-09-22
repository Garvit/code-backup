#include<stdio.h>

int arr[20][3];
int dp[20][3];
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int eval(int i,int state,int n)
{
    if(i>=n) return 0;
    if(dp[i][state]!=-1) return dp[i][state];

    int t=min(eval(i+1,(state+1)%3,n),eval(i+1,(state+2)%3,n));
    int val=arr[i][state]+t;
    //printf("%d %d %d\n",arr[i][state],t,val);
    dp[i][state]=val;
    return dp[i][state];
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
        }
        memset(dp,-1,sizeof(dp));
        int val1=eval(0,0,n);
        int val2=eval(0,1,n);
        int val3=eval(0,2,n);
        int ans=min(val1,min(val2,val3));
        printf("%d\n",ans);

    }
    return 0;
}
