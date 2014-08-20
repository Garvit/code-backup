#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;
vector<pair<int,int> > arr;
bool comp(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}
int main()
{
    int t,n,k,s,num,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&k,&s);
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            arr.push_back(make_pair(num,i+1));
        }
        sort(arr.begin(),arr.end());
        /*for(i=0;i<n;i++)
        {
            if(arr[i].first>s) break;
        }
        sort(arr.begin(),arr.begin()+i,comp);
        sort(arr.begin()+k,arr.end());
        */for(i=0;i<n;i++)
        {
            printf("%d ",arr[i].second);
        }
        printf("\n");
        arr.clear();
    }
}
