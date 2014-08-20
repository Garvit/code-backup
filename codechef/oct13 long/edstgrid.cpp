#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
    int t,n,m,c2,c3;
    char grid[100][100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&n,&m,&c2,&c3);
        int op=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",&grid[i]);
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='B') op++;
            }
        }
        bool flag;
        if(c3*op<=c2*(n*m-op)){
        printf("%d\n",op);
        flag=true;
        }
        else
        {
            printf("%d\n",n*m-op);
            flag=false;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(flag && grid[i][j]=='B') printf("3 %d %d\n",i+1,j+1);
                else if(!flag && grid[i][j]=='W') printf("2 %d %d\n",i+1,j+1);
            }
        }
    }
    return 0;
}
