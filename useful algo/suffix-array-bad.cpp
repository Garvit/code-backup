#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<pair<string,int> > v;
    int l=s.length();
    for(int i=0;i<l;++i)
    {
        v.push_back(make_pair(s.substr(i,l-i),i));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<l;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
