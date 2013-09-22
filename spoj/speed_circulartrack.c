#include<stdio.h>
#include<math.h>
int hcf(int a,int b)
{
    int rem;
    while(b!=0)
    {
        rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        int gcd=hcf(abs(a),abs(b));
        a=a/gcd;
        b=b/gcd;
        printf("%d\n",abs(a-b));
    }
    return 0;
}
