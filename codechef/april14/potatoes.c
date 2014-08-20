#include<stdio.h>
#include<stdbool.h>
bool pr[3000];

void sieve()
{
    int i,j;
    for(i=2;i*i<3000;i++)
    {
        if(pr[i]==0)
        {
            for(j=i*i;j<3000;j+=i)
                pr[j]=1;
        }
    }
}


int main()
{
    sieve();
    int t,x,y,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&y);
        for(i=x+y+1;;i++)
        {
            if(pr[i]==0)
            {
                printf("%d\n",i-x-y);
                break;
            }
        }
    }
}
