#include<stdio.h>

float pos(int a[],int low,int high,int n)
{
    if(low>=high)
    {
        if(n<a[low])
            return low-0.5;
        else
             return low+0.5;

    }
    int mid=(low+high)/2;
    if(n<a[mid])
        return pos(a,low,mid-1,n);
     else if(n>a[mid])
            return pos(a,mid+1,high,n);
    else
         return mid+0.5;

}
main()
{
    int n1,n2,i;
    scanf("%d",&n1);
    int *a=(int*)calloc(n1,sizeof(int));
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n2);
    int *b=(int*)calloc(n2,sizeof(int));
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    float *p=(float*)calloc(n2,sizeof(float));

    for(i=0;i<n2;i++)
        p[i]=pos(a,0,n1-1,b[i]);
    //printf("%2.1f",p);
    int *c=(int*)calloc(n1+n2,sizeof(int));
    int f=0,k=0,j;
    for(i=0;i<n2;i++)
    {

        for(j=f;j<p[i];j++)
        {
            c[k++]=a[j];
        }
        c[k++]=b[i];
        f=floor(p[i])+1;

    }
    for(i=j;i<n1;i++)
        c[k++]=a[i];
    for(i=0;i<(n1+n2);i++)
        printf("%d ",c[i]);


}
