#include<stdio.h>

int lis[1001];
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
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    lis_func(n);
    for(i=0;i<n;i++)
        printf("%d ",lis[i]);
}
