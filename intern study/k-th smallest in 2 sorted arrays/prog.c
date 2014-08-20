#include<stdio.h>

int func(int* arr1,int* arr2,int l1,int r1,int l2,int r2,int k)
{
    int len1=r1-l1+1;
    int len2=r2-l2+1;
    printf("%d %d %d %d %d\n",l1,r1,l2,r2,k);
    if(len1+len2<k) return -1;
    if(len1<=0)
    {
        return arr2[k-1];
    }
    if(len2<=0)
    {
        return arr1[k-1];
    }
    if(len1==1 && len2==1)
    {
        if(k==1)
            return arr1[l1]<arr2[l2]?arr1[l1]:arr2[l2];
        else
            return arr1[l1]>arr2[l2]?arr1[l1]:arr2[l2];
    }
    if(len1==1)
    {
        if(k==1)
            return arr1[l1]<arr2[l2]?arr1[l1]:arr2[l2];
        else if(k==len1+len2)
            return arr1[r1]>arr2[r2]?arr1[r1]:arr2[r2];
        else
        {
            if(arr1[l1]<arr2[k-2]) return arr2[k-2];
            else if(arr1[l1]>arr2[k-1]) return arr2[k-1];
            else return arr1[l1];
        }
    }
    if(len2==1)
    {
        if(k==1)
            return arr1[l1]<arr2[l2]?arr1[l1]:arr2[l2];
        else if(k==len1+len2)
            return arr1[r1]>arr2[r2]?arr1[r1]:arr2[r2];
        else
        {
            if(arr2[l1]<arr1[k-2]) return arr1[k-2];
            else if(arr2[l1]>arr1[k-1]) return arr1[k-1];
            else return arr2[l1];
        }
    }
    int mid1=(l1+r1)/2;
    int mid2=(l2+r2)/2;
    //printf("%d %d\n",mid1,mid2);
    if((mid1-l1+1 + mid2-l2+1)<k)
    {
        if(arr1[mid1]>arr2[mid2])
            return func(arr1,arr2,l1,r1,mid2+1,r2,k-(mid2-l2+1));
        else
            return func(arr1,arr2,mid1+1,r1,l2,r2,k-(mid1-l1+1));
    }
    else
    {
        if(arr1[mid1]>arr2[mid2])
            return func(arr1,arr2,l1,mid1,l2,r2,k);
        else
            return func(arr1,arr2,l1,r1,l2,mid2,k);
    }
}

int main()
{
    int a[]={1,2,3,4};
    int b[]={5,6};
    int k=func(a,b,0,3,0,1,3);
    printf("%d",k);
    return 0;
}
