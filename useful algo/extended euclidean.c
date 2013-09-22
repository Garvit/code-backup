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
int extended_gcd(int a,int b)
{
    int x=0,y=1,lastx=1,lasty=0,q,temp;
    while(b!=0)
    {
        q=a/b;
        temp=a;
        a=b;
        b=temp%b;
        temp=x;
        x=lastx-q*x;
        lastx=temp;
        temp=y;
        y=lasty-q*y;
        lasty=temp;
        //printf("%d %d \n",x,y);
    }
    return lasty;
}

int main()
{
    int a=7,b=11;
    printf("%d",extended_gcd(a,b));
    return 0;
}


