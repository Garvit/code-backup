#include<stdio.h>
#define max(a,b) a>b?a:b
int dp[51][51];
char arr[55][55];
int eval(int i,int j,int h,int w)
{
    if(i>=h || j>=w || i<0 || j<0) return 0;
    if(dp[i][j]) return dp[i][j];
    int m=0;
    if(i>0)
    {
        if(j>0 && arr[i-1][j-1]-arr[i][j]==1) m=max(m,eval(i-1,j-1,h,w));
        if(arr[i-1][j]-arr[i][j]==1) m=max(m,eval(i-1,j,h,w));
        if(j<w-1 && arr[i-1][j+1]-arr[i][j]==1) m=max(m,eval(i-1,j+1,h,w));
    }
    if(i<h-1)
    {
        if(j>0 && arr[i+1][j-1]-arr[i][j]==1) m=max(m,eval(i+1,j-1,h,w));
        if(arr[i+1][j]-arr[i][j]==1) m=max(m,eval(i+1,j,h,w));
        if(j<w-1 && arr[i+1][j+1]-arr[i][j]==1) m=max(m,eval(i+1,j+1,h,w));
    }
    if(j>0 && arr[i][j-1]-arr[i][j]==1) m=max(m,eval(i,j-1,h,w));
    if(j<w-1 && arr[i][j+1]-arr[i][j]==1) m=max(m,eval(i,j+1,h,w));
    dp[i][j]=1+m;
    return dp[i][j];
}
int main()
{
    int h,w,i,j,m,count=1;
    while(1)
    {
        scanf("%d %d",&h,&w);
        if(h==0 && w==0) break;
        char str[55];
        for(i=0;i<h;i++)
        {
            scanf("%s",str);
            for(j=0;j<w;j++)
            {
                arr[i][j]=str[j];
            }
        }

        m=0;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                int v=0;
                if(arr[i][j]=='A') v=eval(i,j,h,w);
                if(m<v)
                    m=v;
            }
        }
        printf("Case %d: %d\n",count,m);
        count++;
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
