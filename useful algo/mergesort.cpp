#include<iostream>
using namespace std;


void merge(int* arr,int l,int mid,int r)
{
    int* temp=new int[r-l+1];

    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i];
            i++;
        }
        else
        {
            temp[k++]=arr[j];
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=r)
    {
        temp[k++]=arr[j++];
    }
    k=0;
    for(i=l;i<=r;i++)
    {
        arr[i]=temp[k++];

    }
}
void sort(int* arr,int l,int r)
{
    if(l>=r) return;

    int mid=(l+r)/2;
    sort(arr,l,mid);
    sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main()
{
    int arr[]={2,1,3,4,6,5};
    sort(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
