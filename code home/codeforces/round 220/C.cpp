#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> grid;
bool visit[1000][1000];
int dp[1000][1000];
string arr;
int n,m;
bool check(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}
int func(int p,int i,int j)
{
    //cout<<"function call "<<arr[p]<<" "<<i<<" "<<j<<endl;
    if(!check(i,j)) return 0;
    if(grid[i][j]!=arr[p]) return 0;
    if(visit[i][j]) return -1;
    if(dp[i][j]!=0) return dp[i][j];


    visit[i][j]=true;
    int ans=0,a;
    a=func((p+1)%4,i-1,j);
    //cout<<i-1<<" "<<j<<" "<<a<<endl;
    if(a==-1){ dp[i][j]=-1; return -1; }
    else ans=max(ans,a);

    a=func((p+1)%4,i+1,j);
    //cout<<i+1<<" "<<j<<" "<<a<<endl;
    if(a==-1){ dp[i][j]=-1; return -1; }
    else ans=max(ans,a);

    a=func((p+1)%4,i,j-1);
    //cout<<i<<" "<<j-1<<" "<<a<<endl;
    if(a==-1){ dp[i][j]=-1; return -1; }
    else ans=max(ans,a);

    a=func((p+1)%4,i,j+1);
    //cout<<i<<" "<<j+1<<" "<<a<<endl;
    if(a==-1){ dp[i][j]=-1; return -1; }
    else ans=max(ans,a);

    visit[i][j]=false;
    if(arr[p]=='A') ans++;
    dp[i][j]=ans;
    return ans;

}
int main()
{
    arr="DIMA";
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        grid.push_back(s);
    }
    int ans=0,a;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a=func(0,i,j);
            //cout<<i<<" "<<j<<" "<<a<<endl;
            if(a==-1) { ans=-1; break;}
            else ans=max(ans,a);
        }
        if(ans==-1) break;
    }
    if(ans==-1) cout<<"Poor Inna!";
    else if(ans==0) cout<<"Poor Dima!";
    else cout<<ans;
    return 0;
}
