#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1; C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}
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
int arr[100000];
int search(int i,int s,int end,int m)
{
    int mid;
    while(s<=end)
    {
        mid=(s+end)/2;
        if(arr[i]+arr[mid]==m) return mid;
        if(arr[i]+arr[mid]<m)
        {
            s=mid+1;
        }
        else
            end=mid-1;
    }
    return s;

}

int main()
{
    int t,n,m,i,count,j,mid;
    t=scan();
    while(t--)
    {
        n=scan();
        count=0;
        m=scan();
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        quicksort(arr,0,n-1);
        i=0;j=n-1;
        while(i<j)
        {
            mid=search(i,i+1,j,m);
            if(arr[i]+arr[mid]==m) count++;
            j=mid-1;
            i++;
        }
        printf("%d\n",count);
    }
    return 0;
}

