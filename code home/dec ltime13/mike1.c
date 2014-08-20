#include<stdio.h>

int arr[501][501];
long long max(long long a,long long b)
{
    return a>b?a:b;
}
int main()
{
    int n,m,i,j,l,x,y;
    long long e1=0,e2=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    scanf("%d",&l);
    for(i=0;i<l;i++)
    {
        scanf("%d %d",&x,&y);
        if(e1!=-1)
        {
            if(x<=n && y<=m) e1+=arr[x][y];
            else e1=-1;
        }
        if(e2!=-1)
        {
            if(x<=m && y<=n) e2+=arr[y][x];
            else e2=-1;
        }

    }
    printf("%lld",max(e1,e2));
    return 0;
}
