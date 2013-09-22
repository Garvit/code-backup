#include<stdio.h>
#include<stdbool.h>
int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1;C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}
int arr[1000000];
int neg[1000000];
bool check[1000000];
int main()
{
    int i,k,n,j;
    while(1)
    {
        n=scan();
        if(n==0) break;
        k=0;
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
            check[i]=0;
            if(arr[i]<0) neg[k++]=i;
        }
        int sum=0,p;
        for(i=k-1;i>=0;i--)
        {
            p=neg[i];
            check[p]=1;
            sum=arr[p];
            j=(p-1+n)%n;
            for(;j!=p;j=(j-1+n)%n)
            {
                sum+=arr[j];
                if(arr[j]<0)
                {
                    i--;
                }
                if(sum<0) check[j]=1;
                else
                    break;

            }
        }
        int count=0;
        for(i=0;i<n;i++)
        {
            if(check[i]==0) count++;
        }
        printf("%d\n",count);

    }

    return 0;
}
