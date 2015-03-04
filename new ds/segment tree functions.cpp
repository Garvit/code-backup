#include <bits/stdc++.h>
#define MAXN 100000
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
struct node
{
    int Min,Max;
    long long sum;
    bool i,d;
};
struct ret
{
    int Min,Max;
    bool i;
};
node tree[3*MAXN];
int arr[MAXN];
void print(node t)
{
    printf("%d %d %lld\n",t.Max,t.Min,t.sum);
    printf("%d %d\n",t.i,t.d);
}
void build(int n,int l,int r)
{
    if(l>r) return;
    else if(l==r)
    {
        tree[n].Min=arr[l];
        tree[n].Max=arr[l];
        tree[n].sum=arr[l];
        tree[n].i=true;
        tree[n].d=true;
        //printf("n: %d\n",n);
        //print(tree[n]);
        return;
    }

    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    tree[n].Min=min(tree[2*n].Min,tree[2*n+1].Min);
    tree[n].Max=max(tree[2*n].Max,tree[2*n+1].Max);
    tree[n].sum=tree[2*n].sum+tree[2*n+1].sum;
    if(tree[2*n].i==true && tree[2*n+1].i==true && tree[2*n].Max<=tree[2*n+1].Min)
        tree[n].i=true;
    else tree[n].i=false;
    if(tree[2*n].d==true && tree[2*n+1].d==true && tree[2*n].Min>=tree[2*n+1].Max)
        tree[n].d=true;
    else tree[n].d=false;

    //printf("n: %d\n",n);
    //print(tree[n]);
}
void update(int n,int l,int r,int i,int value)
{
    if(i>r || i<l || l>r) return;

    if(l==r)
    {
        tree[n].Min+=value;
        tree[n].Max+=value;
        tree[n].sum+=value;
        return;
    }
    update(2*n,l,(l+r)/2,i,value);
    update(2*n+1,(l+r)/2+1,r,i,value);
    tree[n].Min=min(tree[2*n].Min,tree[2*n+1].Min);
    tree[n].Max=max(tree[2*n].Max,tree[2*n+1].Max);
    tree[n].sum=tree[2*n].sum+tree[2*n+1].sum;
    if(tree[2*n].i==true && tree[2*n+1].i==true && tree[2*n].Max<=tree[2*n+1].Min)
        tree[n].i=true;
    else tree[n].i=false;
    if(tree[2*n].d==true && tree[2*n+1].d==true && tree[2*n].Min>=tree[2*n+1].Max)
        tree[n].d=true;
    else tree[n].d=false;

}
int querymax(int n,int l,int r,int i,int j)
{
    if(i>r || j<l || i>j || l>r) return INT_MIN;

    if(l>=i && r<=j) return tree[n].Max;
    int val1=querymax(2*n,l,(l+r)/2,i,j);
    int val2=querymax(2*n+1,(l+r)/2+1,r,i,j);
    return max(val1,val2);
}
long long querysum(int n,int l,int r,int i,int j)
{
    if(i>r || j<l || i>j || l>r) return 0;

    if(l>=i && r<=j) return tree[n].sum;
    long long val1=querysum(2*n,l,(l+r)/2,i,j);
    long long val2=querysum(2*n+1,(l+r)/2+1,r,i,j);
    return val1+val2;
}
ret queryi(int n,int l,int r,int i,int j)
{
    ret val;
    val.Max=INT_MIN;
    val.Min=INT_MAX;
    val.i=true;
    if(i>r || j<l || i>j || l>r) return val;

    if(l>=i && r<=j)
    {
        val.Max=tree[n].Max;
        val.Min=tree[n].Min;
        val.i=tree[n].i;
        return val;
    }
    ret val1=queryi(2*n,l,(l+r)/2,i,j);
    ret val2=queryi(2*n+1,(l+r)/2+1,r,i,j);
    if(val1.i==true && val2.i==true && val1.Max<=val2.Min)
        val.i=true;
    else val.i=false;
    val.Max=max(val1.Max,val2.Max);
    val.Min=min(val1.Min,val2.Min);
    return val;
}
ret queryd(int n,int l,int r,int i,int j)
{
    ret val;
    val.Max=INT_MIN;
    val.Min=INT_MAX;
    val.i=true;
    if(i>r || j<l || i>j || l>r) return val;

    if(l>=i && r<=j)
    {
        val.Max=tree[n].Max;
        val.Min=tree[n].Min;
        val.i=tree[n].d;
        return val;
    }
    ret val1=queryd(2*n,l,(l+r)/2,i,j);
    ret val2=queryd(2*n+1,(l+r)/2+1,r,i,j);
    if(val1.i==true && val2.i==true && val1.Min>=val2.Max)
        val.i=true;
    else val.i=false;
    val.Max=max(val1.Max,val2.Max);
    val.Min=min(val1.Min,val2.Min);
    return val;
}
int main()
{
    int n,m,x,y;
    n=scan();
    m=scan();
    for(int i=0;i<n;++i)
    {
        arr[i]=scan();
    }
    build(1,0,n-1);
    char qr[3];
    while(m--)
    {
        scanf("%s %d %d",qr,&x,&y);
        if(qr[0]=='U')
        {
            update(1,0,n-1,x-1,y-arr[x-1]);
            arr[x-1]=y;
        }
        else if(qr[0]=='M')
        {
            printf("%d\n",querymax(1,0,n-1,x-1,y-1));
        }
        else if(qr[0]=='S')
        {
            printf("%lld\n",querysum(1,0,n-1,x-1,y-1));
        }
        else if(qr[0]=='I')
        {
            printf("%d\n",queryi(1,0,n-1,x-1,y-1).i);
        }
        else if(qr[0]=='D')
        {
            printf("%d\n",queryd(1,0,n-1,x-1,y-1).i);
        }
    }
    return 0;
}
