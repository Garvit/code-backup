#include<stdio.h>
int a[110];
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
    int t,n,inv,localinv,i,j;
    t=scan();
    while(t--)
    {
        localinv=0;inv=0;
        n=scan();
        for(i=0;i<n;i++)
        {
            a[i]=scan();
        }
        if(n==1)
            printf("YES\n");
        else
        {
            for(i=0;i<n-1;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(a[i]>a[j])
                    {
                        inv++;
                    }
                }
            }
            if(inv>=n)
            {
                printf("NO\n");
                continue;
            }
            for(i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1])
                    localinv++;
            }
            if(inv==localinv)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
