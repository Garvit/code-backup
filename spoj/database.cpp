#include<iostream>
#include<stdio.h>
#include<set>
#define getchar getchar_unlocked
using namespace std;
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
set<int> course[10000];
int main()
{
    int t,n,r,z,i,flag=0,x,y;
    t=scan();
    for(z=1;z<=t;z++)
    {
        n=scan();
        r=scan();
        flag=0;
        while(r--)
        {
            x=scan();
            y=scan();
            if(course[x-1].find(y)!=course[x-1].end()) flag=1;
            else course[x-1].insert(y);
        }
        if(flag==1)
        {
            printf("Scenario #%d: impossible\n",z);
        }
        else
        {
            printf("Scenario #%d: possible\n",z);
        }
        for(i=0;i<n;i++)
        {
            course[i].clear();
        }
    }
    return 0;
}
