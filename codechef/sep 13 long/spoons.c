#include<stdio.h>
#define ll long long
ll inline scan()
{
    ll N = 0;
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
ll arr[70][70];
void pascals()
{
    int i,j;
    arr[0][0]=1;
    for(i=1;i<=64;i++)
    {
        arr[i][0]=1;
        for(j=1;j<=i;j++)
        {
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j]);
        }
    }
}
int main()
{
    ll t,n;
    int i;
    pascals();
    t=scan();
    while(t--)
    {
        n=scan();
        for(i=1;i<=64;i++)
        {
            if(arr[i][i/2]>=n)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
