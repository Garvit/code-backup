#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int parent[100001];
int main()
{
    int t,p,a,b,root,q,k,num;
    cin>>t;
    while(t--)
    {
        memset(parent,-1,sizeof(parent));
        cin>>p;
        for(int i=1;i<=p;i++)
        {
            cin>>a>>b;
            if(b==0) root=a;

            parent[a]=b;
        }
        cin>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>num;
            switch(num)
            {
                case 0:
                    cin>>a>>b;
                    parent[b]=a;
                    break;
                case 1:
                    cin>>a;
                    parent[a]=-1;
                    break;
                case 2:
                    cin>>a>>k;
                    int t=k;
                    while(parent[a]!=-1 && t!=0)
                    {
                        a=parent[a];
                        t--;
                    }
                    if(parent[a]==-1)
                        cout<<"0\n";
                    else
                        cout<<a<<endl;
                    break;

            }
        }

    }
    return 0;
}
