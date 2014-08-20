#include<iostream>
#include<map>

using namespace std;
map<string,int> city;
int cost[1000][1000];
int main()
{
    int n,p;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        city.insert(pair<string,int>(s,i));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cost[i][j];
        }
    }
    cin>>p;
    string prev,next;
    cin>>prev;
    ans+=cost[0][city.find(prev)->second];
    for(int i=1;i<p;i++)
    {
        cin>>next;
        ans+=cost[city.find(prev)->second][city.find(next)->second];
        prev=next;
    }
    cout<<ans<<endl;
    return 0;
}
