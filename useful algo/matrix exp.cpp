#include <iostream>
#include <cstdio>
#define MOD 1000000007
#define LL long long
using namespace std;

void matmul(LL a[16][16],LL b[16][16])
{
	LL ans[16][16];
	for(int i=0;i<16;++i)
	{
		for(int j=0;j<16;++j)
		{
			ans[i][j]=0;
			for(int k=0;k<16;++k)
			{
				ans[i][j]+=(a[i][k]*b[k][j])%MOD;
				if(ans[i][j]>=MOD) ans[i][j]-=MOD;
			}
		}
	}
	for(int i=0;i<16;++i)
	{
		for(int j=0;j<16;++j)
			a[i][j]=ans[i][j];
	}
}
void matexp(LL a[16][16],LL exp)
{
	if(exp==1) return;
	LL cp[16][16];
	for(int i=0;i<16;++i)
	{
		for(int j=0;j<16;++j)
			cp[i][j]=a[i][j];
	}
	matexp(cp,exp/2);
	matmul(cp,cp);
	if(exp&1)
	{
		matmul(cp,a);
	}
	for(int i=0;i<16;++i)
	{
		for(int j=0;j<16;++j)
			a[i][j]=cp[i][j];
	}
}
int main()
{
    int st[]={6,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0};
    LL dp[16][16];
    for(int i=0;i<16;++i)
    {
    	for(int j=0;j<16;++j)
    	{
    		int x=i^j;
    		if(x==0) dp[i][j]=6;
    		else if(x==1 || x==2 || x==4 || x==8) dp[i][j]=1;
    		else dp[i][j]=0;
    	}
    }
    int t,n,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
    	scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
    	int s=a+(b<<1)+(c<<2)+(d<<3);
    	//printf("state: %d\n",s);
    	if(n==1)
    	{
    		printf("%d\n",st[s]);
    		continue;
    	}
    	n--;
    	LL arr[16][16];
    	for(int i=0;i<16;++i)
		{
			for(int j=0;j<16;++j)
				arr[i][j]=dp[i][j];
		}
    	if(n>1){ matexp(arr,n);
    	for(int i=0;i<16;++i)
		{
			for(int j=0;j<16;++j)
				printf("%lld ",arr[i][j]);
            printf("\n");
		}
    	}
    	LL newst[16];
    	for(int i=0;i<16;++i)
    	{
    		newst[i]=0;
    		for(int j=0;j<16;++j)
    		{
    			newst[i]+=(arr[i][j]*st[j])%MOD;
    			if(newst[i]>=MOD) newst[i]-=MOD;
    		}
    	}

    	printf("%lld\n",newst[s]);
    }
    return 0;
}

