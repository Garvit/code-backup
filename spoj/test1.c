#include<stdio.h>

int g(int i)
{
    i=i++||i--&&i++;
    //i>>1;
    i=1||0;
    //printf("ok ok\n");
}

int main()
{
   int i=0,j=4;
   for (; (printf("hello:"),i>j?0:j);i++,j--)
       printf("%d ",g(i));
   return 0;
}

/*int main()
{
    int i=123,j=124;
    int *p,*s;
    *(p=&i)*3;
    printf("%d %d %d %d ",i,j,*p,*s);

    p=(s=p,s=&i,s=&j);
    printf("%d %d %d %d",i,j,*p,*s);

    *s+=*p+5;
    printf("%d %d %d %d ",i,j,*p,*s);
    return 0;
}*/
