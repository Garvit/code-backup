#include <bits/stdc++.h>
#define N 250010
using namespace std;

int arr[510][510];
long long tree[4*N];
long long lazy[4*N];
void build(int n,int x1,int y1,int x2,int y2)
{
    if(x1>x2 || y1>y2) return;
    else if(x1==x2 && y1==y2)
    {
        tree[n]=arr[x1][y1];
        return;
    }

    build(4*n-2,x1,y1,(x1+x2)/2,(y1+y2)/2);
    build(4*n-1,(x1+x2)/2+1,y1,x2,(y1+y2)/2);
    build(4*n,x1,(y1+y2)/2+1,(x1+x2)/2,y2);
    build(4*n+1,(x1+x2)/2+1,(y1+y2)/2+1,x2,y2);
    tree[n]=tree[4*n-2]+tree[4*n-1]+tree[4*n]+tree[4*n+1];
    //printf("%d %d %d %d %d\n",x1,y1,x2,y2,tree[n]);
}
void update(int n,int x1,int y1,int x2,int y2,int i1,int j1,int i2,int j2,int value)
{
    //printf("update %d %d %d %d %d %d\n",n,l,r,i,j,value);
    if(lazy[n]!=0)
    {
        tree[n]+=(x2-x1+1)*(y2-y1+1)*lazy[n];

        if(x1!=x2 || y1!=y2)
        {
            lazy[4*n-2]+=lazy[n];
            lazy[4*n-1]+=lazy[n];
            lazy[4*n]+=lazy[n];
            lazy[4*n+1]+=lazy[n];
        }
        lazy[n]=0;
    }

    if(x1>x2 || y1>y2 || i1>i2 || j1>j2 || i1>x2 || j1>y2 || i2<x1 || j2<y1) return;

    if(x1>=i1 && x2<=i2 && y1>=j1 && y2<=j2)
    {
        tree[n]+=((long long)(x2-x1+1))*(y2-y1+1)*value;

        if(x1!=x2 || y1!=y2)
        {
            lazy[4*n-2]+=value;
            lazy[4*n-1]+=value;
            lazy[4*n]+=value;
            lazy[4*n+1]+=value;
        }
        return;
    }
    update(4*n-2,x1,y1,(x1+x2)/2,(y1+y2)/2,i1,j1,i2,j2,value);
    update(4*n-1,(x1+x2)/2+1,y1,x2,(y1+y2)/2,i1,j1,i2,j2,value);
    update(4*n,x1,(y1+y2)/2+1,(x1+x2)/2,y2,i1,j1,i2,j2,value);
    update(4*n+1,(x1+x2)/2+1,(y1+y2)/2+1,x2,y2,i1,j1,i2,j2,value);
    tree[n]=tree[4*n-2]+tree[4*n-1]+tree[4*n]+tree[4*n+1];

}
long long query(int n,int x1,int y1,int x2,int y2,int i1,int j1,int i2,int j2)
{
    if(x1>x2 || y1>y2 || i1>i2 || j1>j2 || i1>x2 || j1>y2 || i2<x1 || j2<y1) return 0;

    if(lazy[n]!=0)
    {
        tree[n]+=(x2-x1+1)*(y2-y1+1)*lazy[n];

        if(x1!=x2 || y1!=y2)
        {
            lazy[4*n-2]+=lazy[n];
            lazy[4*n-1]+=lazy[n];
            lazy[4*n]+=lazy[n];
            lazy[4*n+1]+=lazy[n];
        }
        lazy[n]=0;
    }
    //printf("query %d %d %d %d %d %d %d %d\n",x1,y1,x2,y2,i1,j1,i2,j2);
    if(x1>=i1 && x2<=i2 && y1>=j1 && y2<=j2) return tree[n];
    long long val1=query(4*n-2,x1,y1,(x1+x2)/2,(y1+y2)/2,i1,j1,i2,j2);
    long long val2=query(4*n-1,(x1+x2)/2+1,y1,x2,(y1+y2)/2,i1,j1,i2,j2);
    long long val3=query(4*n,x1,(y1+y2)/2+1,(x1+x2)/2,y2,i1,j1,i2,j2);
    long long val4=query(4*n+1,(x1+x2)/2+1,(y1+y2)/2+1,x2,y2,i1,j1,i2,j2);
    return val1+val2+val3+val4;
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
	    for(int j=0;j<m;++j)
	        scanf("%d",&arr[i][j]);
	build(1,0,0,n-1,m-1);
	int q,x1,x2,y1,y2,k,t;
	scanf("%d",&q);
	while(q--)
	{
	    scanf("%d",&t);
	    if(t==1)
	    {
	        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&k);
	        update(1,0,0,n-1,m-1,x1-1,y1-1,x2-1,y2-1,k);

	    }
	    else{
	        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	        long long ans=query(1,0,0,n-1,m-1,x1-1,y1-1,x2-1,y2-1);;
	        printf("%lld\n",ans);

	    }

	}
	return 0;
}

