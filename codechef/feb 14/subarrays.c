#include<stdio.h>

int main()
{
    int n,k,i,q,j,z;
    int arr[50];
    long long ans=0,left,right,tot;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&k);
        ans=0;
        for(j=0;j<n;j++)
        {
            if(arr[j]==k)
            {
                for(z=j-1;z>=0;z--)
                {
                    if(arr[z]<=k) break;
                }
                left=j-z-1;
                for(z=j+1;z<n;z++)
                {
                    if(arr[z]<k) break;
                }
                right=z-j-1;
                tot=left+right+1;
                ans+=tot*(tot+1)/2-left*(left+1)/2-right*(right+1)/2;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
