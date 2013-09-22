#include<stdio.h>
#include "qsort.h"

main()
{
    int a[]={-2,-1,3,5};
    int n=4;
    quicksort(a,0,3);
    int i;
    for(i=0;i<4;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    for(i=0;i<n;i++)
    {
        int k=i+1;
        int l=n-1;
        while(k<l)
        {
            if(a[i]+a[k]+a[l]==0){
                printf("%d %d %d",a[i],a[k],a[l]);
                break;
            }
            else if(a[i]+a[k]+a[l]>0)
                l=l-1;
            else
                k=k-1;

        }
    }
}
