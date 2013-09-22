#include<stdio.h>
#include<string.h>
#define MAX 100

int ca[MAX];
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N;
}
int main()
{
    int t,i,n,m,j,c,l,minch=0;
    t=scan();
    for(i=0;i<t;i++)
    {
        minch=0;
        n=scan();
        m=scan();
        for(j=0;j<n;j++)
        {
            c=scan();
            l=scan();
            ca[l-1]+=c;
        }
        for(j=0;j<m;j++)
        {
            c=scan();
            l=scan();
            ca[l-1]-=c;
        }
        for(j=0;j<100;j++)
        {
        if(ca[j]<0)
        {
            minch-=ca[j];
        }
        }
        printf("%d\n",minch);
        memset(ca,0,sizeof(ca));

    }

}
