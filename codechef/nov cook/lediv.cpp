#include<iostream>
#include<set>
#include<stdio.h>
#include<cstdio>

using namespace std;
set<int> s;
int a[100000];
int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}

int main()
{
    int t,n,i,min,flag;
    set<int>::iterator it;
    t=scan();
    while(t--)
    {
        n=scan();
        a[0]=scan();
        min=a[0];
        for(i=1;i<n;i++)
        {
            a[i]=scan();

            if(min>a[i])
                min=a[i];
        }
        if(min==1)
        {
            printf("-1\n");
            continue;
        }
        flag=0;
        for(i=2;i<=min/2;i++)
        {
            if(min%i==0)
            {
                s.insert(i);
            }
        }
        s.insert(min);
        for(i=1;i<n;i++)
        {
            for(it=s.begin();it!=s.end();it++)
            {
                if(a[i]%(*it)!=0)
                {
                    s.erase(it);
                }
                if(a[i]%(*it)==0)
                {
                    break;
                }
            }
            if(s.empty())
            {
                flag=1;
                printf("-1\n");
                break;
            }

        }
        if(flag==1)
        {
            continue;
        }
        else
        {
            printf("%d\n",*(s.begin()));
        }
       s.clear();
    }
    return 0;
}
