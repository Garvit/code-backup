#include<stdio.h>
#define MOD 1000000007
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
int dp[1000001];
int ways(int n)
{
    if(dp[n]) return dp[n];
    int val=(ways(n-2)+ways(n-1))%MOD;
    dp[n]=val;
    return dp[n];

}
int main()
{
    int t,i,n,g,w,num,count;
    dp[1]=1;dp[2]=2;
    for(i=3;i<=1000000;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    t=scan();
    while(t--)
    {
        n=scan();
        g=scan();
        w=dp[n];
        count=0;
        num=w;
        while(num>0)
        {
            count+=num&1;
            num=num>>1;
        }
        if(count==g)
            printf("CORRECT\n");
        else printf("INCORRECT\n");
        //printf("%d",count);
    }
    return 0;
}
