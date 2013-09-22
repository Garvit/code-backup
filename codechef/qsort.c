void sort(int *a,int f,int r)
{
    if(f>=r)
        return;
    int p=a[r];
    int i,j=f;
    for(i=f;i<r;i++)
    {
        if(a[i]<=p)
        {
            swap(a,i,j);
            j++;
        }
    }
    swap(a,j,r);
    sort(a,f,j-1);
    sort(a,j+1,r);


}
void swap(int *a,int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
