#include<stdio.h>

int main()
{
    int t,n,m,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(n==1 && m==1)
            printf("0\n");
        else if(n==1 || m==1)
            printf("%d\n",k);
        else
        {
           printf("%d\n",(k+1)/2);
        }
    }
    return 0;
}
