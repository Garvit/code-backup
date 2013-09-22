#include<stdio.h>

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
int eval(int n,int k)
{
    if(n==1) return 1;
    if(n==2)
    {
        if(k%2==0) return 1;
        else return 2;
    }
    int ans=eval(n-1,k+1)+k;
    ans=(ans-1)%n+1;
    //printf("%d\n",ans);
    return ans;
}
int main()
{
    int t,n,i;
    t=scan();
    while(t--)
    {
        n=scan();
        printf("%d\n",eval(n,1));
    }
    return 0;
}
