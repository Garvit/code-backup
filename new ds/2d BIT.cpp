#include <bits/stdc++.h>
#define N 250010
using namespace std;

int arr[510][510];
long long sum[510][510];
long long tree[4][510][510];
int n,m;
void update(int x,int y,int val,int i)
{
    int y1;
    while(x<=n){
        y1=y;
        while(y1<=m)
        {
            tree[i][x][y1]+=val;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}
long long query(int x,int y,int i)
{
    long long ans=0;
    int y1;
    while(x>0){
        y1=y;
        while(y1>0)
        {
            ans+=tree[i][x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return ans;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	    for(int j=1;j<=m;++j){
	        scanf("%d",&arr[i][j]);
	        sum[i][j]=arr[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	    }

	int q,x1,x2,y1,y2,k,t;
	scanf("%d",&q);
	while(q--)
	{
	    scanf("%d",&t);
	    if(t==1)
	    {
	        scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&k);
	        update(x1,y1,k,0);
	        update(x1,y2+1,-k,0);
	        update(x2+1,y1,-k,0);
	        update(x2+1,y2+1,k,0);

	        update(x1,y1,k*(1-y1),1);
	        update(x1,y2+1,k*y2,1);
	        update(x2+1,y1,k*(y1-1),1);
	        update(x2+1,y2+1,-y2*k,1);

	        update(x1,y1,k*(1-x1),2);
	        update(x1,y2+1,k*(x1-1),2);
	        update(x2+1,y1,k*x2,2);
	        update(x2+1,y2+1,-x2*k,2);

	        update(x1,y1,(x1-1)*(y1-1)*k,3);
	        update(x1,y2+1,-y2*(x1-1)*k,3);
	        update(x2+1,y1,-x2*(y1-1)*k,3);
	        update(x2+1,y2+1,x2*y2*k,3);
	    }
	    else{
	        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	        long long val1=query(x2,y2,0)*x2*y2+query(x2,y2,1)*x2+query(x2,y2,2)*y2+query(x2,y2,3);
	        long long val2=query(x2,y1-1,0)*x2*(y1-1)+query(x2,y1-1,1)*x2+query(x2,y1-1,2)*(y1-1)+query(x2,y1-1,3);
	        long long val3=query(x1-1,y2,0)*(x1-1)*y2+query(x1-1,y2,1)*(x1-1)+query(x1-1,y2,2)*y2+query(x1-1,y2,3);
	        long long val4=query(x1-1,y1-1,0)*(x1-1)*(y1-1)+query(x1-1,y1-1,1)*(x1-1)+query(x1-1,y1-1,2)*(y1-1)+query(x1-1,y1-1,3);

	        long long ans=val1-val2-val3+val4;
	        ans+=(sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]);
	        printf("%lld\n",ans);

	    }

	}
	return 0;
}

