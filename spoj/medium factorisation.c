#include<stdio.h>
#include<stdbool.h>
bool pr[10000000];
void sieve()
{
    int start=3,i;

    while(1)
    {
        //printf("\n%d\n",start);
        for(i=3*start;i<10000000;i+=(2*start))
        {
            pr[i]=1;
            //printf("%d ",i);
        }
        start+=2;
        for(i=start;i<10000000;i+=2)
        {
            if(pr[i]==0)
            {
                break;
            }
        }
        if(i>=10000000)
            break;
        start=i;
    }
}
int main()
{
    int n,num,start,i;
    sieve();
    while(scanf("%d",&n)!=EOF)
    {
        printf("1");
        num=n;

        start=2;
        while(num%2==0 || pr[num]!=0)
        {
            if(num%start==0)
            {
                int d=num/start;
                printf(" x %d",start);
                num=d;
            }
            else
            {
                i=start==2?3:start+2;

                for(;i<10000000;i+=2)
                {
                    if(pr[i]==0)
                    {
                        start=i;
                        break;
                    }
                }
            }
        }
        if(pr[num]==0 && num!=1)
        {
            printf(" x %d",num);

        }

    printf("\n");
    }


}

