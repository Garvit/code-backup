#include<stdio.h>
#include<stdbool.h>
#include<time.h>

int main()
{

    int n,i,count=0;
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    bool *b=calloc(n,sizeof(bool));
    int *cycle=calloc(n*3,sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    i=0;
    int p,j=0;
    for(i=0;i<n;i++)
    {
        if(b[i]==0)
        {
            count++;
            p=i;
            while(!b[p])
            {
                b[p]=1;
                cycle[j++]=p+1;
                p=a[p]-1;
            }
            cycle[j++]=p+1;
            cycle[j++]=0;
        }
    }
    cycle[j]=-1;
    int z=j;
    printf("%d\n",count);
    for(z=0;z<j;z++)
    {
        if(cycle[z]==0)
            printf("\n");
        else
            printf("%d ",cycle[z]);
    }

    return 0;
}
