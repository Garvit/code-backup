#include<stdio.h>
//#define getchar getchar_unlocked
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


void matrixmul(long long int a[2][2],long long int b[2][2],int m)
{

    long long int x=((a[0][0]*b[0][0])%m + (a[0][1]*b[1][0])%m)%m;
    long long int y=((a[0][0]*b[0][1])%m + (a[0][1]*b[1][1])%m)%m;
    long long int z=((a[1][0]*b[0][0])%m + (a[1][1]*b[1][0])%m)%m;
    long long int w=((a[1][0]*b[0][1])%m + (a[1][1]*b[1][1])%m)%m;

    a[0][0]=x;
    a[0][1]=y;
    a[1][0]=z;
    a[1][1]=w;


}

void matrixpower(long long int a[2][2],int n,int m)
{
    if(n==0 || n==1)
        return;
    long long int x[2][2]={{1,1},{1,0}};

    matrixpower(a,n/2,m);
    matrixmul(a,a,m);

    if(n%2==1) matrixmul(a,x,m);
    return;
}

int main()
{
    int t,n,m;
    t=scan();
    long long int ans[2][2];
    long long int val;
    while(t--)
    {
        n=scan();
        m=scan();
        ans[0][0]=1;
        ans[0][1]=1;
        ans[1][0]=1;
        ans[1][1]=0;

        matrixpower(ans,n+1,m);
        val=((2*ans[0][0]-2+m)%m-(n%m)+m)%m;
        printf("%lld\n",val);
    }
    return 0;
}
