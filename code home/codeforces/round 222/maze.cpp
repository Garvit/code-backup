#include<iostream>
#include<stdio.h>

using namespace std;

int n,m,k;
bool visited[500][500];
string grid[502];
void dfs(int x,int y)
{
    visited[x][y]=true;
    int i,j;
    for(i=-1;i<=1;i++)
    {
        for(j=-1;j<=1;j++)
        {
            if(i==0 && j==0) continue;
            if(i!=0 && j!=0) continue;
            if(x+i>=0 && x+i<n && y+j>=0 && y+j<m && grid[x+i][y+j]=='.' && !visited[x+i][y+j])
            {
                dfs(x+i,y+j);
            }
        }
    }
    if(k)
    {
        grid[x][y]='X';
        k--;
    }

}
int main()
{
    int i,j;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(grid[i][j]=='.')
            {
                dfs(i,j);
                break;
            }
        }
        if(j!=m) break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<grid[i]<<endl;
    }
    return 0;
}
