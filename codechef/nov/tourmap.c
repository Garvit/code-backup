#include<stdio.h>

char a[5000][50];
char b[5000][50];
int c[5000];
int main()
{
    int t,i,n,totalcost=0,j;
    char *first;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        totalcost=0;
        for(i=0;i<(n-1);i++)
        {
            scanf("%s %s %d$",&a[i],&b[i],&c[i]);
            //printf("%s %s %d$",a[i],b[i],c[i]);
            totalcost+=c[i];

        }

        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(strcmp(a[i],b[j])==0)
                {
                    break;
                }
            }
            if(j==n-1)
            {
                first=a[i];
                break;
            }
        }
        printf("%s %s %d$\n",a[i],b[i],c[i]);
        first=b[i];
        for(i=0;i<n-2;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(strcmp(a[j],first)==0)
                {
                    printf("%s %s %d$\n",a[j],b[j],c[j]);
                    first=b[j];
                    break;

                }
            }
        }
        printf("%d$\n",totalcost);
    }
}
