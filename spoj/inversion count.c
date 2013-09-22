#include<stdio.h>

int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}
long long res=0;
int arr[200001];
int temp[200001];
void merge(int l,int m,int r)
{
    int k=0,i=l,j=m+1;
    while(i<=m && j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];

        }
        else
        {
            temp[k++]=arr[j++];
            res+=m-i+1;

        }
    }
    while(i<=m)
    {
        temp[k++]=arr[i++];

    }
    while(j<=r)
    {
        temp[k++]=arr[j++];
    }
    for(i=0;i<k;i++)
    {
        arr[l+i]=temp[i];
    }
}
void sort(int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        sort(l,m);
        sort(m+1,r);
        merge(l,m,r);
    }
}
int main()
{
    int t,n,i;
    t=scan();
    while(t--)
    {
        n=scan();
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        res=0;
        sort(0,n-1);
        printf("%lld\n",res);

    }
    return 0;
}

