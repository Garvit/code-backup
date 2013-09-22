#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

char str1[200010];
char str2[200010];
vector<int> *arr;
int main()
{
    int t,l,len1,len2;
    long long ans=0;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str1>>str2>>l;
        len1=strlen(str1);
        len2=strlen(str2);
        arr=new vector<int>[len1];
        ans=0;
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(str1[i]==str2[j])
                {
                    arr[i].push_back(j);
                    ans++;
                }
            }
        }
        cout<<ans<<" ";
        for(int i=2;i<=l;i++)
        {
            ans=0;
            for(int j=0;j<=len1-i;j++)
            {
                for(vector<int>::iterator it=arr[j].begin();it!=arr[j].end();)
                {
                    if((*it)+i-1 < len2 && str2[(*it)+i-1]==str1[j+i-1])
                    {
                        ans++;
                        it++;
                    }
                    else
                    {
                        it=arr[j].erase(it);
                    }
                }
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
