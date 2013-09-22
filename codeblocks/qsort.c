#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void quicksort(int *a,int start,int end)
{
    if(start>=end)
        return;
    srand(time(NULL));
    int n;
    n=rand()%(end-start+1)+start;
    swap(a,n,end);
    int s=start,i;
    for(i=start;i<end;i++)
    {
        if(a[i]<a[end])
        {
            swap(a,i,s);
            s++;
        }
    }
    swap(a,s,end);
    quicksort(a,start,s-1);
    quicksort(a,s+1,end);
    return;
}



