#include<stdio.h>

void subcopy(int a[],int start,int len,int dest,int n)
{
    if(start+len>=n)
    {
        printf("wrong input");
        return;
    }
    if(start<dest)
    {
        int i;
        for(i=start+len-1;i>=start;i--)
        {
            if(dest+i-start<n)
            {
                a[dest+i-start]=a[i];
            }
        }
    }
    else
    {
        int i;
        for(i=start;i<=start+len-1;i++)
        {
            a[dest+i-start]=a[i];
        }
    }
}

main()
{
    int a[]={1,2,3,4,5,6,7};
    subcopy(a,2,3,0,7);
    int i;
    for(i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
}
