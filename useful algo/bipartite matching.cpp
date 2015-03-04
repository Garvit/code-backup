#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool graph[100][100];
int matchR[100],matchL[100];
bool seen[100];
int n;
bool bpm(int u)
{
    for(int i=0;i<n;++i)
    {
        if(graph[u][i] && !seen[i])
        {
            seen[i]=true;
            //cout<<"seen: "<<u<<i<<endl;
            if(matchR[i]<0 || bpm(matchR[i]))
            {
                matchR[i]=u;
                matchL[u]=i;
                //cout<<"found "<<i<<u<<endl;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>n;
    string line;
    for(int i=0;i<n;++i){
        cin>>line;
        for(int j=0;j<n;++j)
        {
            graph[i][j]=(line[j]=='Y'?1:0);
        }
    }

    memset(matchR,-1,sizeof(matchR));
    memset(matchL,-1,sizeof(matchL));
    int ans=0;
    for(int i=0;i<n;++i)
    {
        memset(seen,0,sizeof(seen));
        if(bpm(i)) ans++;
    }
    cout<<ans/2*2<<endl;
}
