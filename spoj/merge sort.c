int arr[100001];
int temp[100001];
void merge(int l,int m,int r)
{
    int k=0,i=l,j=m+1;
    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i];

        }
        else
        {
            temp[k++]=arr[j++];
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
        arr[left+i]=temp[i];
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
