#include<stdio.h>
long long int inline scan()
{
    long long int N = 0;
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
    unsigned long long int a=1298074214633706835075030044377087ull;
    printf("%ulld",a);
    return 0;
}
