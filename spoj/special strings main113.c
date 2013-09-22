#include<stdio.h>

int arr[31];
long long dp[31];
void eval()
{
    int i;
    for(i=0;i<=30;i++)
    {
        arr[i]=(i*(i-1)*(i-2))/6;
    }
}
long long int power(long long int base,long long int exp)
{
    long long int result=1;
    while(exp>0)
    {
        if(exp%2==1)
            result=(result*base);
        exp=exp>>1;
        base=(base*base);
        //printf("%lld\n",result);

    }
    return result;


}
int main()
{
    int t,n;
    long long ans=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1) printf("3\n");
        else if(n==2) printf("9\n");
        else
        {
            ans=power(3,n)*26/27;
            printf("%lld\n",ans);
        }
    }
}
