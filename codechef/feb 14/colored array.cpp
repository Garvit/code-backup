#include<iostream>
#include<cstdio>
#include<algorithm>
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
short maxi(short a,short b)
{
    return a>b?a:b;
}
short actual[1000];
short cost[1000][1000];
short sell[1000][1000];
short profit[1000];
int main()
{
    int t,n,m,k;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        k=scan();
        for(int i=0;i<n;i++)
        {
            actual[i]=scan();
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sell[i][j]=scan();
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cost[i][j]=scan();
            }
        }
        for(int i=0;i<n;i++)
        {
            profit[i]=0;
            for(int j=0;j<m;j++)
            {
                profit[i]=maxi(profit[i],sell[i][j]-sell[i][actual[i]-1]-cost[i][j]);
            }

        }
        sort(profit,profit+n,greater<int>());
        int total=0;
        for(int i=0;i<n;i++){
            total+=sell[i][actual[i]-1];
            //cout<<sell[i][actual[i]-1]<<" ";
        }
        //cout<<total<<endl;
        for(int i=0;i<k && profit[i]>0;i++)
            total+=profit[i];
        printf("%d\n",total);

    }
    return 0;
}
