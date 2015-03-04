#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int pos[100001];
int n,k;
bool check(int x)
{
    int last=pos[0],placed=1;
    for(int i=1;i<n;++i)
    {
        if(pos[i]-last>=x)
        {
            placed++;
            if(placed==k) return true;
            last=pos[i];
        }
    }
    return false;
}
void solve()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i) scanf("%d",&pos[i]);
    sort(pos,pos+n);
    int l=0,r=pos[n-1]-pos[0]+1,mid;
    while(r-l>1)
    {
        mid=(l+r)/2;
        printf("mid %d\n",mid);
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
}
int main() {
    int t;
	scanf("%d",&t);
	while(t--)
	{
	    solve();
	}
	return 0;
}
