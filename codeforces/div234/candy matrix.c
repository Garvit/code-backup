#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char matrix[1010][1010];
bool check[1000];
int main()
{
    int n,m,i,j,ans=0;
    scanf("%d %d",&n,&m);
    int pg,ps,flag=0;
    for(i=0;i<n;i++)
    {
        scanf("%s",matrix[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
             if(matrix[i][j]=='G') pg=j;
             else if(matrix[i][j]=='S') ps=j;
        }
        if(ps-pg<0) flag=1;
        else if(check[ps-pg]==0)
        {
            check[ps-pg]=1;
            ans++;
        }
    }
    if(flag==1) printf("-1\n");
    else printf("%d\n",ans);
}
