#include<stdio.h>
#include<limits.h>

//#define getchar getchar_unlocked
int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1;C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}
int arr[100000];
int mintree[3*100000];
int maxtree[3*100000];

inline int max(int a,int b)
{
    return ((a>b)?a:b);
}
inline int min(int a,int b)
{
    return ((a<b)?a:b);
}
void build(int n,int l,int r)
{
    if(l>r) return;
    else if(l==r)
    {
        maxtree[n]=arr[l];
        mintree[n]=arr[l]
        return;
    }

    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    maxtree[n]=max(maxtree[2*n],maxtree[2*n+1]);
    mintree[n]=min(mintree[2*n],mintree[2*n+1]);
}
int query(int n,int l,int r,int i,int j)
{
    if(i>r || j<l || i>j || l>r) return INT_MIN;

    if(l>=i && r<=j) return tree[n];
    int val1=query(2*n,l,(l+r)/2,i,j);
    int val2=query(2*n+1,(l+r)/2+1,r,i,j);
    return max2(val1,val2);
}
int main()
{
    int n,m,i,a,b;
    n=scan();
    for(i=0;i<n;i++)
    {
        arr[i]=scan();
    }
    build(1,0,n-1);
    /*m=scan();
    while(m--)
    {
        a=scan();
        b=scan();
        printf("%d\n",query(1,0,n-1,a-1,b-1));
    }*/
    return 0;
}

