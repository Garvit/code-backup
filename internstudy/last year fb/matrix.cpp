#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

string str[10];
vector<int> pos[10];
vector<int> digit[10];
int grp[10];
void initgrp(int n)
{
    for(int i=0;i<n;i++)
    {
        grp[i]=i;
    }
}

int findgrp(int n)
{
    int i=n;
    while(grp[i]!=i)
    {
        i=grp[i];
    }
    grp[n]=i;
    return i;
}
int main()
{
    string inp;

    int n;
    cin>>inp;
    n=inp.length();
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    initgrp(n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(str[i][j]=='Y')
            {
                int g1=findgrp(i);
                int g2=findgrp(j);
                if(g1!=g2) grp[g1]=g2;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        grp[i]=findgrp(i);
        cout<<"i: group: "<<grp[i]<<endl;
        pos[grp[i]].push_back(i);
        digit[grp[i]].push_back(inp[i]);
    }
    string ans(n,'-');
    for(int i=0;i<n;i++)
    {
        if(digit[i].size()!=0){
            cout<<"grp: "<<i<<endl;
        sort(pos[i].begin(),pos[i].end());
        sort(digit[i].begin(),digit[i].end());
        for(int j=0;j<digit[i].size();j++)
        {
            ans[pos[i][j]]=digit[i][j];
        }
        }
    }
    cout<<ans;
}

