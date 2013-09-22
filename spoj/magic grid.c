#include<stdio.h>
#define max(a,b) a>b?a:b
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
int arr[501][501];
int dp[501][501];
int eval(int i,int j,int l,int w)
{
    if(dp[i][j]) return dp[i][j];
    if(i==l-1 && j==w-1) return 0;

    int val1,val2,ans=arr[i][j];
    if(i==l-1)
    {
        val1=eval(i,j+1,l,w);
        if(val1<0)
            ans+=val1;

    }
    else if(j==w-1)
    {
        val2=eval(i+1,j,l,w);
        if(val2<0)
            ans+=val2;
    }
    else
    {
        val1=eval(i,j+1,l,w);
        val2=eval(i+1,j,l,w);
        int v=max(val1,val2);
        if(v<0)
        {
            ans+=v;
        }

    }
    dp[i][j]=ans;

    return dp[i][j];
}
int main()
{
    int t,r,c,i,j;
    t=scan();
    while(t--)
    {
        r=scan();
        c=scan();
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                arr[i][j]=scan();
            }
        }
        int ans=eval(0,0,r,c);
        /*for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d ",dp[i][j]);
            }
            printf("\n");
        }*/
        if(ans>0)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n",1-ans);
        }
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
