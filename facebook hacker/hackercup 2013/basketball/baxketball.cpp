#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;

int main()
{
    int t,n,p,m,sp,h;
    string nam;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n>>m>>p;
        vector<pair<pair<int,int>,string > > data;
        string *names=new string[n];
        queue<int> odd,even;
        for(int i=0;i<n;i++){
        cin>>nam>>sp>>h;
        data.push_back(make_pair(make_pair(sp,h),nam));
        }
        sort(data.begin(),data.end());
        int k=0;
        for(int i=n-1;i>=0;i--)
        {
            names[k++]=data[i].second;
        }
        vector<string> players;
        int *arr=new int[n];
        int start=2*p-1,limit=(n+1)/2;
        k=0;
        for(int i=start;i>=1;i-=2)
            arr[k++]=i;
        while(k<limit)
        {
            arr[k++]=start+2;
            start+=2;
        }
        int min=m%limit;
        /*for(int i=0;i<limit;i++)
        {
            cout<<arr[i]<<endl;
        }*/
        for(int i=min,j=0;j<p;j++,i=(i+1)%limit)
                players.push_back(names[arr[i]-1]);

        start=2*p,limit=n/2;
        k=0;
        for(int i=start;i>=2;i-=2)
            arr[k++]=i;
        while(k<limit)
        {
            arr[k++]=start+2;
            start+=2;
        }
        min=m%limit;
        /*for(int i=0;i<limit;i++)
        {
            cout<<arr[i]<<endl;
        }*/
        for(int i=min,j=0;j<p;j++,i=(i+1)%limit)
                players.push_back(names[arr[i]-1]);

        sort(players.begin(),players.end());
        cout<<"Case #"<<z<<": ";
        for(int i=0;i<2*p;i++)
        {
            cout<<players[i]<<" ";
            //cout<<data[i].second<<" "<<data[i].first.first<<" "<<data[i].first.second<<endl;
        }
        cout<<endl;
    }
    return 0;
}
