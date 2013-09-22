#include<stdio.h>

int arr[100][100];
void pascals(int n)
{
    int i,j;
    arr[0][0]=1;
    for(i=1;i<n;i++)
    {
        arr[i][0]=1;
        for(j=1;j<=i;j++)
        {
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%10000007;
        }
    }
}

int main()
{

    int n,r;
    scanf("%d %d",&n,&r);
    pascals(n);
    if(n<r) printf("-1");
    else printf("%d",arr[n-1][r-1]);
    return 0;
}
