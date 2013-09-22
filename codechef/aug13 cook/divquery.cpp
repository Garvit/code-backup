#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cassert>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define MP make_pair
#define pb push_back

#define maxn 100000
#define maxd 100000
#define maxq 100000

typedef long long  LL;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;

int tree[maxn+1];

int read(int idx)
{
	int sum = 0;
	while (idx > 0) sum =(sum+tree[idx]), idx -= (idx & -idx);
	return sum;
}

void update(int idx ,int val)
{
	while (idx <= maxn) tree[idx]=(tree[idx]+val), idx += (idx & -idx);
}

vector<int> divs[maxd+1],bucket[maxd+1];
int arr[maxn+1];
vector<pii> qs[maxq+1];
int ans[maxq+1];

int main()
{
   int i,j,k,n,q;

   // Generates the divisors
   for(i=1;i<=maxd;i++)
      for(j=i;j<=maxd;j+=i) divs[j].pb(i);

   scanf("%d%d",&n,&q);
   assert(n>=1 && n<=maxn);
   assert(q>=1 && q<=maxq);

   for(i=1;i<=n;i++)
   {
      scanf("%d",&arr[i]);
      assert(arr[i]>=1 && arr[i]<=maxd );

      for(j=0;j<divs[arr[i]].size();j++)
      {
         int d=divs[arr[i]][j];
         // The bucket stores the indexes where a paritular divisor=d appeared
         bucket[d].pb(i);
      }
   }

   // Stores the queries for offline answering
   for(i=0;i<q;i++)
   {
      int a,b;

      scanf("%d%d%d",&a,&b,&k);

      assert(a>=1 && a<=n);
      assert(b>=a && b<=n);
      assert(k>=1 && k<=maxd );

      qs[k].pb( MP(i,MP(a,b)) );
   }

   // For each number that appeared as a divisior builds the tree and solves the query where K=that number
   for(i=1;i<=maxd;i++)
   {
      for(j=0;j<bucket[i].size();j++)
         update(bucket[i][j],+1);

      for(j=0;j<qs[i].size();j++)
      {
         int id=qs[i][j].first;
         int a=qs[i][j].second.first;
         int b=qs[i][j].second.second;

         ans[id]= read(b) - read(a-1);
      }

      for(j=0;j<bucket[i].size();j++)
         update(bucket[i][j],-1);
   }

   for(i=0;i<q;i++)
        printf("%d\n",ans[i]);


	return 0;
}


