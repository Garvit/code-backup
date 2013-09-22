#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
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
    int *p,*q;
    p=(int *)40;
    q=(int *)60;
    //printf("%d\n",q-p);
    int a=25;
    int b=sqrt(a);
    printf("%d",b);

}
