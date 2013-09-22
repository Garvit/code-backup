#include<stdio.h>
#define MOD 1000000007
int arr[1001][1001];
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

void pascals()
{
    int i,j;
    arr[0][0]=1;
    for(i=1;i<=1000;i++)
    {
        arr[i][0]=1;
        for(j=1;j<=i;j++)
        {
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%MOD;
        }
    }
}
int a[1000];
int main()
{
    int t,n,i,ans;
    t=scan();
    pascals();
    while(t--)
    {
        n=scan();
        ans=0;
        for(i=0;i<n;i++)
        {
            a[i]=scan();
        }
        if(n==1) printf("1\n");
        else
        {
            for(i=n/2+1;i<=n;i++)
            {
                ans=(ans+arr[n][i])%MOD;
            }
            printf("%d\n",ans);
        }

    }
    return 0;
}
