#include<iostream>
#include<stdio.h>
#include<list>
#include<bitset>
using namespace std;
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }
    return N;
}
char mat[51][51];
bitset<51> dp[51];
int w,h;
struct node
{
  int x,y;
  node()
  {x = y = -1;}
  void set(int a,int b)
  {
      x=a;
      y=b;
  }
};
char bfs(int x,int y)
{
    list<node> queue;
    node temp,temp2;
    
    temp.set(x,y);
    queue.push_back(temp);
    
    char ans =1,prev = 'A';
    while(!queue.empty())
    {
        temp = queue.front();
        queue.pop_front();
        if(mat[temp.x][temp.y] ==prev+1)
        {
            prev = mat[temp.x][temp.y];
            ans++;
       }
  
        for(int i = max(0,temp.x-1);i<=min(h-1,temp.x+1);i++)
        {
            for(int j= max(0,temp.y-1);j<=min(w-1,temp.y+1);j++)
            {
                if(dp[i][j] == 0 && mat[i][j] == mat[temp.x][temp.y]+1 )
                {
                    temp2.set(i,j);
                    queue.push_back(temp2);
                    dp[i][j] = 1;
                }
            }
        }
    }
    return ans;
}
int main()
{
    char ans;
    for(int k=1;;k++)
    {
        h = scan();
        w = scan();
        if(w == 0 && h == 0) break;
        for(int i=0;i<h;i++)
        {
            dp[i].reset();
            for(int j=0;j<w;j++)
            {
                mat[i][j] = getchar_unlocked(); 
            }
            getchar_unlocked();
        }
        ans = 0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                if(mat[i][j] == 'A')
                    ans = max(bfs(i,j),ans);
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}



