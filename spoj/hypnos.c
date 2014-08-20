#include<stdio.h>
#include<stdbool.h>

bool check[10000];


int breaking(int n)
{
    int sum=0,d;
    while(n>0)
    {
        d=n%10;
        n=n/10;
        sum+=d*d;
    }
    return sum;
}
int main()
{
    int n,count=0;
    scanf("%d",&n);
    while(n!=1)
    {
        n=breaking(n);
        if(check[n]==1)
        {
            printf("-1");
            break;
        }
        check[n]=1;
        count++;
        //printf("%d\n",n);
    }
    if(n==1) printf("%d",count);

    return 0;
}
