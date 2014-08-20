#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long ans;
void merge(int* a,int l,int m,int r)
{
    int n=r-l+1,i=l,j=m+1,k=0;
    int t[n];
    while(i<=m && j<=r)
    {
        if(a[i]<=a[j])
        {
            t[k++]=a[i++];
        }
        else
        {
            t[k++]=a[j++];
            ans+=m-i+1;
        }
    }
    while(i<=m)
        t[k++]=a[i++];
    while(j<=r)
        t[k++]=a[j++];

    for(i=l;i<=r;i++)
    {
        a[i]=t[i-l];
    }
}

void mergesort(int *a,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}


int main() {

    int t,i,n;
    int *arr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        arr=calloc(n,sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        mergesort(arr,0,n-1);
        printf("%lld\n",ans);

    }
    return 0;
}

