#include<stdio.h>
#include<stdbool.h>
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
bool leap(int n)
{
    if(n%400==0) return true;
    if(n%100==0) return false;
    if(n%4==0) return true;
}
int main()
{
    int t,d,m,y,num;
    t=scan();
    int arr[]={0,31,59,90,120,151,181,212,243,273,304,334};
    char *day[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    while(t--)
    {
        d=scan();
        m=scan();
        y=scan();
        num=0;
        num+=(y-2001)*365;
        num+=(y-2001)/4 - (y-2001)/100 + (y-2001)/400;

        num+=arr[m-1];
        if(leap(y) && m>2) num++;
            num+=d;

        printf("%s\n",day[num%7]);

    }
    return 0;
}
