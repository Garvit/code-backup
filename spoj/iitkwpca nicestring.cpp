#include<iostream>
#include<cstring>
#include<set>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        set<string> diff;
        string s="";
        char c;
        while((c=getchar())!='\n')
        {
            if(c==' ')
            {
                 if(s!="") diff.insert(s);
                 s="";
            }
            else s=s+c;
        }
        if(s!="") diff.insert(s);
        cout<<diff.size()<<endl;


    }
}
