#include<stdio.h>
#define MOD 1000000007
int arr[301][301];
void pascals()
{
    int i,j;
    arr[0][0]=1;
    for(i=1;i<=300;i++)
    {
        arr[i][0]=1;
        for(j=1;j<=i;j++)
        {
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%MOD;
        }
    }
}

int main()
{
    pascals();
    int n,w,t,r;
    scanf("%d %d %d %d",&n,&w,&t,&r);
    long long val1=arr[n][w],val2=arr[n-w][r];
    long long ans=(val1*val2)%MOD;
    printf("%lld\n",ans);
    return 0;
}
