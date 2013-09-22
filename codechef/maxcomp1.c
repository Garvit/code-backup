#include<stdio.h>
#include<string.h>

int *s;
int *e;
int *c;
int ans[49];
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}

int main()
{
    int t,i,n,j,k;
    t=scan();
    for(i=0;i<t;i++)
    {
        memset(ans,0,sizeof(ans));
        n=scan();
        s=calloc(n,sizeof(int));
        e=calloc(n,sizeof(int));
        c=calloc(n,sizeof(int));
        for(j=0;j<n;j++)
        {
            s[j]=scan();
            e[j]=scan();
            c[j]=scan();
        }

        for(j=1;j<49;j++)
        {
            for(k=0;k<n;k++)
            {
                if(e[k]<=j && ans[j]<(ans[s[k]]+c[k]))
                    ans[j]=ans[s[k]]+c[k];
            }
        }
        printf("%d\n",ans[48]);

    }
    return 0;
}
