#include<stdio.h>
#include<string.h>
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
int arr[50];
int main()
{
    int t,n,m,k,ans,i,j;
    char str[55];
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        k=scan();
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            for(j=0;j<m;j++)
            {
                if(str[j]=='*')
                    arr[i]++;
            }
        }
        ans=0;
        quicksort(arr,0,n-1);

        for(i=0;i<n;i++)
        {
            if(i==k)
            {
                break;
            }
            if(arr[i]>m/2)
            {
                if((k-i)%2!=0)
                {
                    if(i!=0 && arr[i-1]<arr[i])
                    {
                        arr[i-1]=m-arr[i-1];
                    }
                    else
                    {
                        arr[i]=m-arr[i];
                    }
                }
                break;
            }
            arr[i]=m-arr[i];
        }
        if(i==n)
        {
            if((k-i)%2!=0)
                {
                    arr[i-1]=m-arr[i-1];
                }
        }
        for(i=0;i<n;i++)
        {
            ans+=arr[i];
        }
        printf("%d\n",ans);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
