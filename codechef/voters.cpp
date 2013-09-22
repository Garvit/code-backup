#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<map>
#include<utility>
#include<list>
using namespace std;

map< int,int > m;
list<int> l;
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N;
}

int main()
{
    int n1,n2,n3,n,num=0;
    map<int,int>::iterator it;
    n1=scan();
    n2=scan();
    n3=scan();
    while(n1--)
    {
        n=scan();
        it=m.find(n);
        if(it==m.end())
        {
            m[n]=1;
        }
        else
        {
            it->second++;
        }

    }
    while(n2--)
    {
        n=scan();
        it=m.find(n);
        if(it==m.end())
        {
            m[n]=1;
        }
        else
        {
            it->second++;
        }

    }
    while(n3--)
    {
        n=scan();
        it=m.find(n);
        if(it==m.end())
        {
            m[n]=1;
        }
        else
        {
            it->second++;
        }

    }
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second > 1)
        {
            num++;
            l.push_back(it->first);
        }
    }
    l.sort();
    list<int>::iterator lit;
    printf("%d\n",num);
    for(lit=l.begin();lit!=l.end();lit++)
    {
        printf("%d\n",*lit);
    }
    return 0;
}
