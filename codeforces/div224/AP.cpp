#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int arr[100000];
int main()
{
    int n,d1,d2=0,count=0,pos;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(n==1)
    {
        printf("-1\n");
    }
    else
    {
        sort(arr,arr+n);
        d1=arr[1]-arr[0];
        for(int i=2;i<n;i++)
        {
            if(arr[i]-arr[i-1]!=d1)
            {
                count++;
                if(count>1 && arr[i]-arr[i-1]!=d2) { printf("0\n"); return 0; }
                else {pos=i; d2=arr[i]-arr[i-1];}
            }
        }
        if(count==0)
        {
            if(d1==0) printf("1\n%d\n",arr[0]);
            else if(n==2 && d1%2==0) printf("3\n%d %d %d\n",arr[0]-d1,arr[0]+d1/2,arr[1]+d1);
            else printf("2\n%d %d\n",arr[0]-d1,arr[n-1]+d1);
        }
        else
        {
            if(count==1 && d2==2*d1) printf("1\n%d\n",arr[pos]-d1);
            else if(count==n-2 && d1==2*d2) printf("1\n%d\n",arr[0]+d2);
            else printf("0\n");
        }
    }
    return 0;
}
