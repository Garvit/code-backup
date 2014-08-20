#include<stdio.h>
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


int main()
{
    int n,k,i;
    n=scan();
    long long *arr=malloc(n*sizeof(long long));
    k=scan();
    long long min,max;
    arr[0]=scan();
    min=max=arr[0];
    for(i=1;i<n;i++)
    {
        arr[i]=scan();
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    if(k==0)
    {
        for(i=0;i<n;i++)
        {
            printf("%lld ",arr[i]);
        }
    }
    else if(k&1)
    {
        for(i=0;i<n;i++)
        {
            printf("%lld ",(max-arr[i]));
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            printf("%lld ",(arr[i]-min));
        }
    }
    return 0;
}
