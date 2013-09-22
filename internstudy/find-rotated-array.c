#include<stdio.h>

int pivot(int* a,int l,int r)
{
    int m;
    while(a[l]>a[r])
    {
        m=(l+r)/2;
        if(a[m]<=a[r])
        {
            r=m;
        }
        else
        {
            l=m+1;
        }
    }
    return l;
}
int main()
{
    int a[]={4,5,6,7,1,2,3};
    int l=0,r=6,n=2;
    int m=(l+r)/2;
    printf("%d\n",pivot(a,l,r));
    while(l<=r)
    {
        if(a[m]==n)
        {
            printf("%d",m);
            break;
        }
        if(a[m]<=a[r])
        {
            if(a[m]<n && n<=a[r])
                l=m+1;
            else
                r=m-1;
        }
        else
        {
            if(a[l]<=n && n<a[m])
                r=m-1;
            else
                l=m+1;
        }
        m=(l+r)/2;
    }


}
