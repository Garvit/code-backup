#include<iostream>
#include<stdio.h>
using namespace std;

int pos[1000002];
int tree[1000002];
int digit[1000002];
int n,m;
void update(int x,int val)
{
    while(x<=n)
    {
        tree[x]+=val;
        x+=(x & -x);
    }
}
int query(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=tree[x];
        x-=(x&-x);
    }
    return sum;
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}
int find(int i)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(query(mid)<i) l=mid+1;
        else r=mid-1;
    }
    return l;
}
int main()
{
    int num,size=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&pos[i]);
    }
    int e,less;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&e);
        if(e==-1)
        {
            less=0;
            for(int j=0;j<m;j++)
            {
                if(pos[j]>size) break;
                int p=find(pos[j]-j);
                //cout<<p<<endl;
                update(p,-1);
                less++;
            }
            size-=less;
        }
        else
        {
            digit[i]=e;
            size++;
            update(i,1);
        }
        //print();
    }
    if(size==0) printf("Poor stack!");
    else
    {
        for(int i=0;i<size;i++)
        {
            printf("%d",digit[find(i+1)]);
        }
    }
    return 0;
}
