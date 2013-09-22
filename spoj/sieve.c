#include<stdio.h>
#include<stdbool.h>
#define MAX 1000000000
bool pr[MAX];
void sieve()
{
    int start=3,i,limit=ceil(sqrt(MAX));

    while(1)
    {
        for(i=start*start;i<MAX;i+=(2*start))
        {
            pr[i]=1;

        }
        start+=2;
        for(i=start;i<limit;i+=2)
        {
            if(pr[i]==0)
            {
                break;
            }
        }
        if(i>=limit)
            break;
        start=i;
    }
}
int main()
{
    sieve();
    printf("ok");
}
