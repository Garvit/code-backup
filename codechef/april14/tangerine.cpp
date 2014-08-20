#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;
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
vector<pair<int,int> > lr;
vector<pair<int,int> > ab;
int main()
{
    int n,k,p,t,x,y;
    t=scan();
    while(t--)
    {
        n=scan();
        k=scan();
        p=scan();
        int f1=-1,f2=-1,tx=0,ty=0;
        bool flag=false;
        for(int i=0;i<k;i++)
        {
            x=scan();
            y=scan();
            if(x>y){ f1=i; tx=x;ty=y;}
            else
                lr.push_back(make_pair(x,y));
        }
        for(int i=0;i<p;i++)
        {
            x=scan();
            y=scan();
            if(x>y) f2=i;
            ab.push_back(make_pair(y,x));
        }
        if(f1!=-1)
        {
            if(f2==-1){ printf("No\n");}
            else
            {
                if(tx>=ab[f2].second && ty<=ab[f2].first)
                    flag=true;
                else printf("No\n");
            }
        }
        else flag=true;

        if(flag){
        if(p>k) printf("No\n");
        else{
        sort(lr.begin(),lr.end());
        sort(ab.begin(),ab.end());
        int j=0,i;
        for(i=0;i<lr.size();i++)
        {
            if(j>=p){ i=lr.size(); break;}
            if(lr[i].first<=ab[j].first)
            {
                if(lr[i].second>ab[j].first)
                    break;
            }
            else j++;
        }
        if(i<lr.size()) printf("No\n");
        else printf("Yes\n");
        }}

        lr.clear();
        ab.clear();
    }
    return 0;
}

