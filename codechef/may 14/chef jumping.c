#include<stdio.h>

int main()
{
    long long int a;
    scanf("%lld",&a);
    int m=a%6;
    if(m==0 || m==1 || m==3)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
