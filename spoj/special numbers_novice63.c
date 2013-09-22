#include<stdio.h>
#include<math.h>

long long inline scan()
{
    long long N = 0;
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
long long arr[61];
void eval()
{
    arr[1]=1;
    arr[2]=1;
    int i;
    for(i=4;i<=60;i+=2)
    {
        arr[i]=arr[i-2]+arr[i-2]*2;
    }
    for(i=3;i<60;i+=2)
    {
        arr[i]=arr[i-1];
    }
}

int main()
{
    long long t,n;
    t=scan();
    eval();
    while(t--)
    {
        n=scan();
        int l=log(n)/log(2);
    }
    return 0;
}
}
