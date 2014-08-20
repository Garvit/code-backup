#include<stdio.h>
#include<string.h>
char grid[5002][5002];
int row[5002];
int count[5002];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,m,i,j,ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",grid[i]);
    }
    for(j=0;j<m;j++)
    {
        memset(count,0,sizeof(count));
       for(i=0;i<n;i++)
       {
           if(grid[i][j]=='1')
                row[i]++;
            else  row[i]=0;
          count[row[i]]++;

       }
       int c=0;
       for(i=j+1;i>=1;i--)
        {
            if(count[i])
            {
                c+=count[i];
                ans=max(ans,i*c);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
