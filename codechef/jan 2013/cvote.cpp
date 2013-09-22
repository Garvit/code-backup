#include<iostream>
#include<map>
#include<utility>
#include<cstdio>
#include<string.h>
#include<cstring>

using namespace std;
map <string,string> chefcountry;
map <string,int> chefvote;
map <string,int> countryvote;

int main()
{
    int n,m,i,max1=0,max2=0,t;
    string s1,s2,maxchef,maxcountry,temp;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>s1>>s2;
        chefcountry[s1]=s2;
        chefvote[s1]=0;
        if(countryvote.find(s2)==countryvote.end())
            countryvote[s2]=0;
    }
    for(i=0;i<m;i++)
    {
        cin>>s1;
        chefvote[s1]++;
        t=chefvote[s1];
        if(t>max1)
        {
            max1=t;
            maxchef=s1;
        }
        else if(t==max1)
        {
            if(strcmp((char*)s1.c_str(),(char*)maxchef.c_str())<0)
            {
                maxchef=s1;
            }
        }
        temp=chefcountry[s1];
        countryvote[temp]++;
        t=countryvote[temp];
        if(t>max2)
        {
            max2=t;
            maxcountry=temp;
        }
        else if(t==max2)
        {
            if(strcmp((char*)temp.c_str(),(char*)maxcountry.c_str())<0)
            {
                maxcountry=temp;
            }
        }
    }
    cout<<maxcountry<<"\n"<<maxchef<<endl;
    return 0;
}
