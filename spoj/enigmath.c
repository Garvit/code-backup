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
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        int g=gcd(a,b);
        printf("%d %d\n",b/g,a/g);
    }
}
