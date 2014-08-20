#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int curh,curw,h,w,n,ans=0;
        cin>>h>>w>>n;
        vector<string> grid(h);
        for(int i=0;i<h;i++)
        {
            cin>>grid[i];
        }
        curh=-1;curw=0;
        //cout<<curh<<" "<<curw<<endl;
        char next;
        for(int i=1;i<=n;i++)
        {
            cin>>next;
            if(next=='L' && curw>0)
            {
                if(curh>=0)
                {
                    if(grid[curh][curw-1]!='S')
                    {
                        curw--;
                        if(grid[curh][curw]=='T'){ ans++; grid[curh][curw]='D';}
                    }
                }
                else
                    curw--;
            }
            else if(next=='R' && curw<w-1)
            {
                if(curh>=0)
                {
                    if(grid[curh][curw+1]!='S')
                    {
                        curw++;
                        if(grid[curh][curw]=='T'){ ans++; grid[curh][curw]='D';}
                    }
                }
                else
                    curw++;

            }
            else if(next=='D' && curh<h-1 && grid[curh+1][curw]!='S')
            {
                curh++;
                if(grid[curh][curw]=='T') { ans++; grid[curh][curw]='D';}

            }
            while(curh<h-1 && grid[curh+1][curw]=='E')
                curh++;
            //cout<<curh<<" "<<curw<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
