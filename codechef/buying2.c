#include<stdio.h>

int inline scan()
{
    int N=0;
    char C;
    C=getchar();
    while(C<'0' || C>'9') C=getchar();
    while(C>='0' && C<='9')
    {
        N=(N<<3) + (N<<1) + C - '0';
        C=getchar();
    }
    return N;
}

int main()
{
    int t,n,x,i,j,v,total,min,buy1,buy2;
    t=scan();
    while(t--)
    {
        total=0;min=0;
        n=scan();
        x=scan();
        while(n--)
        {
            v=scan();
            total+=v;
            if(min==0 || v<min)
                min=v;
        }
        buy1=total/x;
        buy2=(total-min)/x;
        if(buy1==buy2)
            printf("-1\n");
        else
            printf("%d\n",buy1);

    }

    return 0;
}
