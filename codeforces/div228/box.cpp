#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[101];
int main()
{
    int n,ans=0,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    while(true)
    {
        bool flag=false;
        int level=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]>=level)
            {
                flag=true;
                level++;
                arr[i]=-1;
                //cout<<i<<" "<<arr[i]<<endl;
            }

        }
        if(flag==false) break;
        else
        {
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
