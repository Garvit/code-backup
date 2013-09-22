#include<stdio.h>
#include<stdbool.h>
#include<string.h>

char arr[200][200];
int dp[200][200];
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
int eval(int i,int j,bool face,int m,int n)
{

    if(dp[i][j]) return dp[i][j];
    if(arr[i][j]=='#') return 0;
    int val1=0,val2=0,max;
    if(face==1)
    {

        if(j+1<n)
            val1=eval(i,j+1,face,m,n);
        if(i+1<m)
            val2=eval(i+1,j,!face,m,n);

        max=val1>val2?val1:val2;
    }
    else
    {
        if(j-1>=0)
            val1=eval(i,j-1,face,m,n);
        if(i+1<m)
            val2=eval(i+1,j,!face,m,n);

        max=val1>val2?val1:val2;
    }
    if(arr[i][j]=='T') max++;
    dp[i][j]=max;
    return dp[i][j];
}
int main()
{
    int t,n,m,i,j,ans;
    t=scan();
    while(t--)
    {
        m=scan();
        n=scan();
        for(i=0;i<m;i++)
        {
            scanf("%s",arr[i]);

        }
        ans=eval(0,0,1,m,n);
        printf("%d\n",ans);         //face=1 for right and 0 for left
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
