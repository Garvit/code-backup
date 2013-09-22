#include<stdio.h>
#include<iostream>
#include<vector>

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

char colour[2001];
vector<int> arr[2001];

bool eval(int i)
{
    //printf("%d %c\n",i,colour[i]);
    if(arr[i].empty()) return false;
    vector<int>::iterator it;
    for(it=arr[i].begin();it!=arr[i].end();it++)
    {
        //printf("%d\n",*it);
        if(colour[*it]==colour[i]) return true;

        else if(colour[*it]=='\0')
        {
            colour[*it]=(colour[i]=='R')?'B':'R';
            bool f=eval(*it);
            if(f) return true;
        }
    }
    return false;
}
int main()
{
    int t,i,z,n,m,a,b;
    bool flag;
    t=scan();
    for(z=1;z<=t;z++)
    {
        flag=false;
        n=scan();
        m=scan();
        while(m--)
        {
            a=scan();
            b=scan();
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(i=1;i<=n;i++)
        {
            if(colour[i]=='\0')
                { colour[i]='R'; flag=eval(i); }

            if(flag==true)
                    break;
        }
        printf("Scenario #%d:\n",z);
        if(flag==true)
        {
            printf("Suspicious bugs found!\n");
        }
        else
            printf("No suspicious bugs found!\n");

        for(i=1;i<=n;i++)
        {
            //printf("%c ",colour[i]);
            colour[i]='\0';
            arr[i].clear();
        }
    }
    return 0;
}
