#include<stdio.h>

int main()
{
    int i,t,n,min;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int *arr=malloc(n*sizeof(int));
        scanf("%d",&arr[0]);
        min=arr[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]<min)
                min=arr[i];
        }
        int diff=0;
        for(i=0;i<n;i++)
        {
            diff+=(arr[i]-min);
        }
        if(diff%n==0) printf("%d\n",n);
        else printf("%d\n",n-1);
    }
    return 0;
}
