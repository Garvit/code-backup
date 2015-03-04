#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10010];
int lis(int n)
{
	vector<int> d;
	for(int i=0;i<n;++i)
	{
		vector<int>::iterator it=lower_bound(d.begin(),d.end(),arr[i]);
		if(it==d.end()) d.push_back(arr[i]);
		else *it=arr[i];
	}
	return d.size();
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
    	scanf("%d",&arr[i]);
    }
    printf("%d",n-lis(n));
    return 0;
}

