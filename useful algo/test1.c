#include<stdio.h>

int compare(int *a,int *b)
{
    return *a-*b;
}
int main()
{
    int a[]={2,5,1,8};
    qsort(a,4,sizeof(int),compare);
    int i;
    for(i=0;i<4;i++)
    {
        printf("%d ",a[i]);
    }
    if(0)
        printf("ok");
    return 0;
}
