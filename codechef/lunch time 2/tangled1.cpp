#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<vector>
#include<map>
#include<utility>
#include<set>
using namespace std;

string str1;
string str2;
map<string, pair<long long,long long> > *arr;
set<string> set1;
set<string> set2;
int main()
{
    int t,l,len1,len2,useset=1;
    long long ans=0;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str1>>str2>>l;
        len1=str1.length();
        len2=str2.length();
        useset=1;
        arr=new map<string,pair<long long,long long> >;
            for(int j=0;j<len1;j++)
            {
                string s=str1.substr(j,1);
                map<string,pair<long long,long long> >::iterator it=arr->find(s);
                if(it==arr->end())
                {
                    arr->insert(pair<string,pair<long long,long long> >(s,pair<long long,long long>(1,0)));
                }
                else
                {
                    (it->second).first++;
                }
            }
            for(int j=0;j<len2;j++)
            {
                string s=str2.substr(j,1);
                map<string,pair<long long,long long> >::iterator it=arr->find(s);
                if(it!=arr->end())
                {
                    (it->second).second++;
                    set1.insert(s);
                }
            }
            ans=0;
            for(map<string,pair<long long,long long> >::iterator it=arr->begin();it!=arr->end();it++)
            {
                ans+=(it->second).first * (it->second).second;
            }
            cout<<ans<<" ";
            delete arr;
        for(int i=2;i<=l;i++)
        {
            arr=new map<string,pair<long long,long long> >;
            if(useset==1)
            {
                for(set<string>::iterator it=set1.begin();it!=set1.end();it++)
                {
                    int p=str1.find(*it);
                    while(p!=-1 && p<len1-i+1)
                    {
                        string s=str1.substr(p,i);
                        map<string,pair<long long,long long> >::iterator ite=arr->find(s);
                        if(ite==arr->end())
                        {
                            arr->insert(pair<string,pair<long long,long long> >(s,pair<long long,long long>(1,0)));
                            set2.insert(s);
                            //cout<<s<<endl;
                        }
                        else
                        {
                            (ite->second).first++;
                        }
                        p=str1.find(*it,p+1);
                        //cout<<"p:-"<<p<<endl;
                    }
                }
                //cout<<"exit\n";
                for(set<string>::iterator it=set2.begin();it!=set2.end();)
                {
                    int p=str2.find(*it);
                    //cout<<*it<<" "<<p<<endl;
                    if(p==-1)
                    {
                        set2.erase(it++);
                    }
                    else
                    {
                        map<string,pair<long long,long long> >::iterator ite=arr->find(*it);
                        while(p!=-1)
                        {
                            (ite->second).second++;
                            p=str2.find(*it,p+1);
                        }
                        ++it;
                    }

                }
                //cout<<"set2 "<<set2.size()<<endl;
                useset=2;
                set1.clear();
            }
            else
            {
                for(set<string>::iterator it=set2.begin();it!=set2.end();it++)
                {
                    int p=str1.find(*it);
                    //cout<<"else"<<*it<<p<<endl;
                    while(p!=-1 && p<len1-i+1)
                    {
                        string s=str1.substr(p,i);
                        map<string,pair<long long,long long> >::iterator ite=arr->find(s);
                        if(ite==arr->end())
                        {
                            arr->insert(pair<string,pair<long long,long long> >(s,pair<long long,long long>(1,0)));
                            set1.insert(s);
                            //cout<<s<<endl;
                        }
                        else
                        {
                            (ite->second).first++;
                        }
                        p=str1.find(*it,p+1);
                    }
                }
                for(set<string>::iterator it=set1.begin();it!=set1.end();)
                {
                    int p=str2.find(*it);
                    if(p==-1)
                    {
                        set1.erase(it++);
                    }
                    else
                    {
                        map<string,pair<long long,long long> >::iterator ite=arr->find(*it);
                        while(p!=-1)
                        {
                            (ite->second).second++;
                            p=str2.find(*it,p+1);
                        }
                        ++it;
                    }

                }
                useset=1;
                set2.clear();
            }

            ans=0;
            for(map<string,pair<long long,long long> >::iterator it=arr->begin();it!=arr->end();it++)
            {
                ans+=(it->second).first * (it->second).second;
            }
            cout<<ans<<" ";
            delete arr;

        }
        cout<<"\n";
        set1.clear();
        set2.clear();
    }
    return 0;
}

