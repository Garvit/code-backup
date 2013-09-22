#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

string str1,str2;
int ans[200010];
string *sa;
void build()
{
    for(int i=0;i<str1.length();i++)
    {
        sa[i]=str1.substr(i);
    }
    sort(sa,sa+str1.length());
    for(int i=0;i<str1.length();i++)
    {
        cout<<sa[i]<<endl;
    }
}
int main()
{
    int l1,l2,t;
    cin>>t;
    while(t--)
    {
        cin>>str1>>str2;
        l1=str1.length();
        l2=str2.length();
        sa=new string[l];
        build();
    }

}
