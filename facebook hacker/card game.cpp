#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
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
int arr[10000][10000];
void pascals()
{
    int i,j;
    arr[0][0]=1;
    for(i=1;i<10000;i++)
    {
        arr[i][0]=1;
        for(j=1;j<=i;j++)
        {
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%MOD;
        }
    }
}
int a[10000];

int main()
{
    int t,n,k,z;
    long long int ans=0;
    t=scan();
    pascals();
    for(z=1;z<=t;z++)
    {
        n=scan();
        k=scan();
        ans=0;
        for(int i=0;i<n;i++)
        {
            a[i]=scan();
        }
        sort(a,a+n);
        for(int i=n-1;i>=k-1;i--)
        {
            ans=(ans+((a[i]%MOD)*arr[i][k-1])%MOD)%MOD;
        }
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}
