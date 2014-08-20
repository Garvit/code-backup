#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> mid;
int main()
{
    int n,s,num,csum=0,jsum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s);
        for(int j=1;j<=s/2;j++)
        {
            scanf("%d",&num);
            csum+=num;
        }
        if(s%2)
        {
            scanf("%d",&num);
            mid.push_back(num);
        }
        for(int j=(s+1)/2+1;j<=s;j++)
        {
            scanf("%d",&num);
            jsum+=num;
        }
    }
    sort(mid.begin(),mid.end());

    for(int i=mid.size()-1,c=1;i>=0;i--,c++)
    {
        if(c%2) csum+=mid[i];
        else jsum+=mid[i];
    }
    printf("%d %d",csum,jsum);
}
