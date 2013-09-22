#include<stdio.h>

void swap(int a[],int i,int j);
main()
{
    int n,k1,k2,k3;
    scanf("%d",&k1);
    scanf("%d",&k2);
    scanf("%d",&k3);
    scanf("%d",&n);
    int *a;
    a=calloc(n,sizeof(int));
    int i=0;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }


    int j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<k1)
        {
            swap(a,i,j);
            j++;
        }

    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<k2)
        {
            swap(a,i,j);
            j++;
        }

    }
    j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<k3)
        {
            swap(a,i,j);
            j++;
        }

    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;

}
