#include<stdio.h>

void rotate(int **a,int s,int e)
{
    if(s>=e) return;

    int i;
    for(i=s;i<e;i++)
    {
        int temp=a[e-i+s][s];
        a[e-i+s][s]=a[e][e-i+s];
        a[e][e-i+s]=a[i][e];
        a[i][e]=a[s][i];
        a[s][i]=temp;
    }
    rotate(a,s+1,e-1);

}
main()
{
    int n;
    scanf("%d",&n);
    int i;
    int **a=(int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
    {
        a[i]=(int*)calloc(n,sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    rotate(a,0,n-1);
    for(i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
