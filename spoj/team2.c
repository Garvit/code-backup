#include<stdio.h>

int main()
{
    int a,b,c,d,t=1;
    long long int max,second;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
    {
        max=a>b?a:b;
        second=a<b?a:b;
        if(c>=second && c<=max)
        {
            second=c;
        }
        else if(c>max)
        {
            second=max;
            max=c;
        }

        if(d>=second && d<=max)
        {
            second=d;
        }
        else if(d>max)
        {
            second=max;
            max=d;
        }
        printf("Case %d: %lld\n",t,(max+second));
        t++;
    }
    return 0;
}
