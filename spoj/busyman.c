#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define getchar getchar_unlocked
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
int start[100000];
int end[100000];
int dp[1000001];
int main()
{
    int t,n,i;
    t=scan();
    while(t--)
    {
        n=scan();
        for(i=0;i<n;i++)
        {
            start[i]=scan();
            end[i]=scan();
        }
        quicksort(end,start,0,n-1);
        int p=0,max=0;
        for(i=0;i<=end[n-1];i++)
        {
            max=0;
            while(end[p]<i && p<n)
                p++;
            if(end[p]==i && p<n)
            {
                while(end[p]==i && p<n)
                {
                    if(dp[start[p]]+1>max)
                    {
                        max=dp[start[p]]+1;
                    }
                    p++;
                }
            }
            if(i!=0) dp[i]=max>dp[i-1]?max:dp[i-1];
            else dp[i]=max;
            //printf("%d ",dp[i]);
        }
        printf("%d\n",dp[i-1]);
    }
    return 0;
}
