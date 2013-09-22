#include<stdio.h>
int arr[60];
int hcf(int a,int b)
{
    int x=(a>b)?a:b;
    int y=(a<=b)?a:b;
    int temp;
    while(y!=0)
    {
        temp=y;
        y=(x%y);
        x=temp;
    }
    return x;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int gcd,j;
        scanf("%d",&arr[0]);
        gcd=arr[0];
        for(j=1;j<n;j++)
        {
            scanf("%d",&arr[j]);
            gcd=hcf(gcd,arr[j]);
        }
        for(j=0;j<n;j++)
        {
            printf("%d ",(arr[j]/gcd));
        }
        printf("\n");

    }
    return 0;
}
