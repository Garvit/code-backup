#include<stdio.h>

int lis[1001];
int dis[1001];
int arr[1001];
void lis_func(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        lis[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
}
void dis_func(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        dis[i]=1;
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i] && dis[i]<dis[j]+1)
            {
                dis[i]=dis[j]+1;
            }
        }
    }
}
int main()
{
    int t,n,i,max;
    scanf("%d",&t);
    while(t--)
    {
        max=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        lis_func(n);
        dis_func(n);
        for(i=0;i<n;i++)
        {
            if(lis[i]+dis[i]-1 > max)
            {
                max=lis[i]+dis[i]-1;
            }
        }
        printf("%d\n",max);

    }

}

