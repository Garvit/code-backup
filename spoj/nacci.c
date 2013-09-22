#include<stdio.h>
#include<math.h>
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
void matrixmul(long long int a[30][30],long long int b[30][30],int n,int m)
{
    long long int x[30][30];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x[i][j]=0;
            for(k=0;k<n;k++)
            {
                x[i][j]=(x[i][j]+(a[i][k]*b[k][j])%m)%m;

            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=x[i][j];
        }

    }



}

void matrixpower(long long int a[30][30],int p,int n,int m)
{
    if(p==0 || p==1)
        return;
    long long int x[30][30];
    memset(x,0,sizeof(x));
    int i;
    for(i=0;i<n-1;i++)
    {
        x[i][0]=1;
        x[i][i+1]=1;
    }
    x[n-1][0]=1;

    matrixpower(a,p/2,n,m);
    matrixmul(a,a,n,m);

    if(p%2==1) matrixmul(a,x,n,m);
    return;
}
long long int arr[30][30];
long long int ans[30][30];
int main()
{
    int t,n,k,l,i,j,num,m;
    t=scan();
    while(t--)
    {
        n=scan();
        k=scan();
        l=scan();
        m=pow(10,k);
        num=n*(n-1)/2;
        if(l<n)
        {
            printf("%d\n",l%m);
        }
        else if(l==n)
        {
            printf("%d\n",num%m);
        }
        else
        {
            for(i=0;i<n-1;i++)
            {
                arr[i][0]=1;
                arr[i][i+1]=1;
            }
            arr[n-1][0]=1;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i+j>=n) ans[i][j]=0;
                    else
                    {
                        ans[i][j]=n-(i+j);
                    }
                }
            }
            ans[0][0]=num;

            matrixpower(arr,l-n,n,m);
            matrixmul(ans,arr,n,m);

            printf("%lld\n",ans[0][0]);
        }
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
