#include<stdio.h>

int main()
{
    int t,i,j;
    int a[10];
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {

        scanf("%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);

          int min=a[0],p=0,min2,p2;
            for(j=1;j<10;j++)
            {
                if(a[j]<min || (p==0 && a[j]<=min))
                {
                    min=a[j];
                    p=j;
                }
            }
            if(p!=0)
            {
                for(j=0;j<=min;j++)
                {
                    printf("%d",p);
                }
                printf("\n");
            }
            else
            {

                printf("1");

                for(j=0;j<=min;j++)
                {
                    printf("0");
                }

                printf("\n");
            }



    }

    return 0;
}
