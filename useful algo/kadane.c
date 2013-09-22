#include<stdio.h>

int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int a[]={1,4,10,4};

    int maxi=a[0],i,n=4,curr=a[0];
    int start=0,end=0;

    for(i=1;i<n;i++)
    {
        if(a[i]>curr+a[i])
        {
            curr=a[i];
            if(maxi<curr)
            {
                start=i;end=i;
                maxi=curr;
            }
        }
        else
        {
            curr=curr+a[i];
            if(maxi<curr)
            {
                maxi=curr;
                end=i;
            }
        }


    }
    printf("%d %d %d",start,end,maxi);
}
