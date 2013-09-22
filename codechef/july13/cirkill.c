#include<stdio.h>

int x[30];
int y[30];
int main()
{
    int t,n,i,j,k,total;
    float centerx,centery,slopea,slopeb;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        total=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    slopea=(y[j]-y[i])/(x[j]-x[i]);
                    slopeb=(y[])
                    total++;

                }
            }
        }
    }
}
