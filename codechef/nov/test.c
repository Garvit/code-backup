#include<stdio.h>

main()
{
    char c[6000];
    int num=123456789;

    sprintf(c,"%d",num);
    printf("%c",c[2]);
}
