#include<stdio.h>
#include<limits.h>
#define min(a,b) a<b?a:b
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
int tree[3*100000];

void build(int n,int l,int r)
{
    if(l>r) return;
    else if(l==r)
    {
        tree[n]=arr[l];
        //printf("%d %d %d %d\n",n,l,r,tree[n]);
        return;
    }

    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    tree[n]=min(tree[2*n],tree[2*n+1]);
    //printf("%d %d %d %d\n",n,l,r,tree[n]);
}
int query(int n,int l,int r,int i,int j)
{
    if(i>r || j<l || i>j || l>r) return INT_MAX;

    if(l>=i && r<=j) return tree[n];
    int val1=query(2*n,l,(l+r)/2,i,j);
    int val2=query(2*n+1,(l+r)/2+1,r,i,j);
    return min(val1,val2);
}
int main()
{
    int t,z,n,m,i,a,b;
    t=scan();
    for(z=1;z<=t;z++){
    n=scan();
    m=scan();
    for(i=0;i<n;i++)
    {
        arr[i]=scan();
    }
    build(1,0,n-1);
    printf("Scenario #%d:\n\n",z);
    while(m--)
    {
        a=scan();
        b=scan();
        printf("%d\n",query(1,0,n-1,a-1,b-1));
    }
    memset(tree,0,sizeof(tree));
    }
    return 0;
}
