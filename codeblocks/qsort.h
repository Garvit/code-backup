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
    /*srand(time(NULL));
    int pivot;
    pivot=(rand()%(end-start+1))+start;
    printf("%d\n",pivot);
    swap(a,pivot,end);*/
    int s=0,i;
    for(i=start;i<end;i++)
    {
        if(a[i]<a[end])
        {
            swap(a,i,s);
            s++;
        }
    }
    printf("s:- %d\n",s);
    swap(a,s,end);
    quicksort(a,start,s-1);
    quicksort(a,s+1,end);
    return;
}




