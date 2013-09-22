#include<stdio.h>
#include<time.h>

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
void swap(int *a,int *b,int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;

    temp=b[i];
    b[i]=b[j];
    b[j]=temp;
}
void quicksort(int *a,int *b,int start,int end)
{
    if(start>=end)
        return;
    srand(time(NULL));
    int n;
    n=rand()%(end-start+1)+start;
    swap(a,b,n,end);
    int s=start,i;
    for(i=start;i<end;i++)
    {
        if(a[i]<a[end])
        {
            swap(a,b,i,s);
            s++;
        }
    }
    swap(a,b,s,end);
    quicksort(a,b,start,s-1);
    quicksort(a,b,s+1,end);
    return;
}
int arr[100000];
int ori[100000];
int main()
{
    int t,x,n,z,i,temp,j;
    long long int count;
    t=scan();
    for(z=1;z<=t;z++)
    {
        x=scan();
        n=scan();
        count=0;
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
            ori[i]=i;
        }
        quicksort(arr,ori,0,n-1);
        for(i=0,j=n-1;i<j;i++)
        {
            while(arr[i]+arr[j]>x)
            {
                j--;
            }
            if(arr[i]+arr[j]==x)
            {
                if(ori[i]<ori[j]) count++;
                temp=j-1;
                while(arr[temp]==arr[j] && temp>i)
                {
                    count++;
                    temp--;
                }
            }
        }
        printf("%d. %lld\n",z,count);
        memset(arr,0,sizeof(arr));
        memset(ori,0,sizeof(ori));
    }
    return 0;
}
