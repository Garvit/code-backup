#include<stdio.h>

main()
{
    int n,i,q,k,j,count;
    long *a;
    scanf("%d",&n);
    long **time=calloc(n,sizeof(long*));
    for(i=0;i<n;i++)
    {
        time[i]=calloc(2,sizeof(long));
        scanf("%ld",&time[i][0]);
        scanf("%ld",&time[i][1]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        count=0;
        scanf("%d",&k);
        a=calloc(k,sizeof(long));
        for(j=0;j<k;j++)
        {
            scanf("%ld",&a[j]);

        }
        int z;
        for(z=0;z<n;z++)
            {
                for(j=0;j<k;j++)
                {
                    if(a[j]>=time[z][0] && a[j]<=time[z][1]){
                        count++;
                        break;
                        }
                }
            }
        printf("%d\n",count);
    }


}
