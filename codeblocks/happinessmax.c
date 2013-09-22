#include<stdio.h>
#include<stdlib.h>

typedef
struct tup
{
    int left,right,sum;
} tup;
tup* max_happ(int a[],int low,int high,int n);
int Min(int a[],int low,int high);
main()
{
    int n,i;
    scanf("%d",&n);
    int *a=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //tup *t=(tup*)malloc(sizeof(tup));
    tup *t=max_happ(a,0,n-1,n);
    printf("left limit %d\n",t->left);
    printf("right limit %d\n",t->right);
    printf("sum %d\n",t->sum);

}
tup* max_happ(int a[],int low,int high,int n)
{
    tup *t=(tup*)calloc(1,sizeof(tup));
    if(low>=n)
    {
        t->left=high;
        t->right=high;
        t->sum=a[high]*a[high];
        return t;
    }
    if(low>=high)
    {
        t->left=low;
        t->right=low;
        t->sum=a[low]*a[low];
        return t;
    }
    tup *left,*right,*cross;
    int mid=Min(a,low,high);
    left=max_happ(a,low,mid-1,n);
    right=max_happ(a,mid+1,high,n);
    int psum=0,i;
    for(i=low;i<=high;i++)
        psum+=a[i];
    psum*=a[mid];
    t->left=low;
    t->right=high;
    t->sum=psum;
    if(left->sum>=right->sum && left->sum>=psum)
    {
        return left;
    }
    else if(right->sum>=left->sum && right->sum>=psum)
    {
        return right;
    }
    else
        return t;

}
int Min(int a[],int low,int high)
{
    int i,min=a[low],p=low;
    for(i=low+1;i<=high;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            p=i;
        }
    }
    return p;

}
