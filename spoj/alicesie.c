#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main()
{
    int t,n,count=0,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        count=ceil(n/2.0);
        printf("%d\n",count);

    }
    return 0;
}
