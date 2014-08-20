#include<stdio.h>

int a[300];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    while(a[0]>0)
    {
        printf("P");
        a[0]--;
        if(a[0]!=0) printf("RL");
    }
    printf("R");
    for(i=1;i<n;i++)
    {
        while(a[i]>0)
        {
            printf("P");
            a[i]--;
            if(a[i]!=0) printf("LR");
        }
        if(i!=n-1) printf("R");
    }

    return 0;
}
