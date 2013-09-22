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
int arr[50000];
int tree[3*50000];

inline int max2(int a,int b)
{
    return ((a>b)?a:b);
}
inline int max3(int a,int b,int c)
{
    return max2(a,max2(b,c));
}
void build(int n,int l,int r)
{
    if(l>r) return;
    else if(l==r)
    {
        tree[n]=arr[l];
        return;
    }

    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    tree[n]=max2(tree[2*n],tree[2*n+1]);
}
void update(int n,int l,int r,int i,int j,int value)
{
    if(i>r || j<l || i>j || l>r) return;

    if(l==r)
    {
        tree[n]+=value;
        return;
    }
    update(2*n,l,(l+r)/2,i,j,value);
    update(2*n+1,(l+r)/2+1,r,i,j,value);
    tree[n]=max2(tree[2*n],tree[2*n+1]);

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
    m=scan();
    while(m--)
    {
        a=scan();
        b=scan();
        printf("%d\n",query(1,0,n-1,a-1,b-1));
    }
    return 0;
}
