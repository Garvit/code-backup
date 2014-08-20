#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int arr[100000];
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+k,greater<int>());
    int ans=1+arr[0];
    for(int i=1;i<k;i++)
    {
        if(i+1+arr[i]>ans)
            ans=arr[i]+1+i;
    }
    printf("%d",ans+1);
    return 0;
}
