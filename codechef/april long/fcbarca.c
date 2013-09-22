#include<stdio.h>
#define MOD 1000000007

long long int power(long long int base,long long int exp)
{
    long long int result=1;
    while(exp>0)
    {
        if(exp%2==1)
            result=(result*base) % MOD;
        exp=exp>>1;
        base=(base*base)%MOD;
        //printf("%lld\n",result);

    }
    return result;


}
long long mem[11][1001];
void eval()
{
    int k,n;
    for(k=1;k<=10;k++)
    {
        mem[k][2]=k;
        mem[k][3]=k*(k-1);
        for(n=4;n<=1000;n++)
        {
            mem[k][n]=(power(k,n-1)-mem[k][n-1]+MOD)%MOD;
        }
    }
}
int main()
{
    int t,n,k;
    long long ans;
    eval();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%lld\n",mem[k][n]);
    }
    return 0;
}
