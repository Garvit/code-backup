#include<stdio.h>

int  inline scan()
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
    int t,n,i;
    t=scan();
    for(i=0;i<t;i++)
    {
        n=scan();
        int j,c=1,p;
        p=scan();
        for(j=1;j<n;j++)
        {
            int s;
            s=scan();
            if(s<=p)
            {
                c++;
                p=s;
            }

        }
        printf("%d\n",c);

    }
    return 0;
}
