#include<stdio.h>
#include<stdbool.h>
#define MAX 1000000

bool arr[1000001];

int sumdigits(int n)
{
    int d=0;
    while(n>0)
    {
        d+=n%10;
        n=n/10;
    }
    return d;
}
int main()
{
    int i,sum,count=0;
    for(i=1;i<MAX;i++)
    {
        sum=i+sumdigits(i);
        //printf("%d\n",sum);
        if(sum<=1000000) arr[sum]=1;
    }
    for(i=1;i<MAX;i++)
    {
        if(arr[i]==0)
        {
          printf("%d\n",i);
          //count++;
        }
    }
    //printf("%d",count);
    return 0;
}
