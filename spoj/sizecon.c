#include<stdio.h>

int main()
{
    int t,n,sum=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n>0) sum+=n;
    }
    printf("%d",sum);
    return 0;
}
