#include<stdio.h>

int arr[100];
int main()
{
    int t,n,i,k,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        scanf("%d",&k);
        num=arr[k-1];
        int ans=1;
        for(i=0;i<n;i++)
        {
            if(arr[i]<num) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
