#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#define getchar getchar_unlocked
using namespace std;
long long int inline scan()
{
    long long int N = 0;
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
int arr[1000000];
int main()
{
    int n,i,height;
    long long int m;
    n=scan();
    m=scan();
    for(i=0;i<n;i++)
    {
        arr[i]=scan();
    }
    sort(arr,arr+n);
    long long int ans=0,t;

    for(i=n-1;i>0;i--)
    {
        t=(arr[i]-arr[i-1])*(n-i);
        if(t<(m-ans))
            ans+=t;
        else
        {
            //printf("%lld %lld %d ",m,ans,i);
            int h=ceil((m-ans)/(double)(n-i));
            //printf("%d ",h);
            height=arr[i]-h;
            break;
        }
        //printf("%lld ",ans);
    }
    printf("%d",height);
    return 0;
}
