#include<iostream>
#include<algorithm>
#include<stdio.h>
#define getchar getchar_unlocked
using namespace std;

int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1; C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}
int arr[100000];
int main()
{
    int t,n,m,count,j;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        count=0;
        for(int i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            j=lower_bound(arr,arr+n,m-arr[i])-arr;
            if(j!=i && j!=n && arr[i]+arr[j]==m) count++;

        }
        printf("%d\n",count/2);
    }
    return 0;
}
