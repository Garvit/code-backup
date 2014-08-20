#include<stdio.h>
#define getchar getchar_unlocked
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

int main()
{
    int n,i,j;
    n=scan();
    while(n--)
    {
        i=scan();
        j=scan();
        int a=0;
        while(i!=j)
        {
            if(i>j)i=i/2;
            else j=j/2;
            a++;
        }
        printf("%d\n",a);
    }
    return 0;
}
