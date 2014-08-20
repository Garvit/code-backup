#include<stdio.h>

int gcd(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,i,num,hcf;
    scanf("%d",&n);
    scanf("%d",&hcf);
    for(i=1;i<n;i++)
    {
        scanf("%d",&num);
        hcf=gcd(hcf,num);
    }
    printf("%d",hcf*n);
    return 0;
}
