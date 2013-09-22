#include<stdio.h>
#include<stdbool.h>

int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}
int main()
{
    int t,i,n,m,j;
    t=scan();
    for(i=0;i<t;i++)
    {
        n=scan();
        m=scan();
        int pj,k=0;
        bool *b=calloc(n,sizeof(bool));
        int *a=calloc(n-m,sizeof(int));
        for(j=0;j<m;j++)
        {
            pj=scan();
            b[pj-1]=true;
        }
        for(j=0;j<n;j++)
        {
            if(b[j]==0)
                a[k++]=j+1;
        }
        for(j=0;j<k;j=j+2)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
        for(j=1;j<k;j=j+2)
        {
            printf("%d ",a[j]);
        }
        printf("\n");
        free(a);

    }
        return 0;
}
