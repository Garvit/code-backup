#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[1000000];
int main()
{
    int n,i,j;
    long long x;
    scanf("%d %lld",&n,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int suc=0,half=0;
    for(i=0;i<n;i++)
    {
        if(x>=(arr[i]+1)/2)
        {
            half++;
            x-=(arr[i]+1)/2;
        }

    }
    for(i=0;i<half;i++)
    {
        if(x>=arr[i]/2)
        {
            x-=arr[i]/2;
            suc++;
        }
    }
    printf("%d %d",n-half,suc);
    return 0;
}
