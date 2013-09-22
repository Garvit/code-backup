#include<stdio.h>

int main()
{
    int n,a,b,num1=0,num2=0,num3=0,ans=1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d/%d",&a,&b);
        if(b==2)
        {
            num2++;
        }
        else
        {
            if(a==1)
            {
                num1++;
            }
            else
            {
                num3++;
            }
        }
    }
    ans+=num3;
    num1-=num3;
    if(num1<0) num1=0;

    ans+=(num2>>1);
    if(num2&1) {ans++; num1-=2; if(num1<0) num1=0;}

    ans+=((num1+3)>>2);

    printf("%d\n",ans);
    return 0;
}
