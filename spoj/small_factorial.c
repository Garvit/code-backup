#include<stdio.h>

short fact[200];
int main()
{
    int t,n,m,temp,x,j,i;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=0;temp=0;
        fact[0]=1;
        for(i=2;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                x=fact[j]*i+temp;
                fact[j]=x%10;
                temp=x/10;
            }
            while(temp>0)
            {
                m++;
                fact[m]=temp%10;
                temp=temp/10;
            }
        }
        //printf("m :%d\n",m);
        for(i=m;i>=0;i--)
        {
            printf("%d",fact[i]);
        }
        printf("\n");
        memset(fact,0,sizeof(fact));
    }
}
