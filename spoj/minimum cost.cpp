#include<iostream>
#include<cstring>

using namespace std;

string s,t;
int cost[1001][1001];
int min(int a,int b)
{
    return a<b?a:b;
}
int dp(int i,int j)
{
    if(i==s.length())
    {
        return 30*(t.length()-j);
    }
    else if(j==t.length())
    {
        return 15*(s.length()-i);
    }

    if(cost[i][j]) return cost[i][j];

    int ans;
    if(s[i]==t[j])
        ans=dp(i+1,j+1);
    else
        ans=min(15+dp(i+1,j),30+dp(i,j+1));

    cost[i][j]=ans;
    return cost[i][j];
}

int main()
{
    int ans;
    cin>>s;
    while(s[0]!='#')
    {
        cin>>t;

        ans=dp(0,0);
        cout<<ans<<endl;
        memset(cost,0,sizeof(cost));
        cin>>s;
    }
    return 0;
}
