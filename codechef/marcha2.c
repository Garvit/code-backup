#include<stdio.h>
#include<stdlib.h>

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
    int t,k,numl,prev;

    t=scan();
    while(t--)
    {
        k=scan();
        prev=1;
        while(k--)
        {
            numl=scan();

            if(numl>prev)
            {
                prev=-1;
                break;
            }
            prev=prev-numl;
            prev=prev<<1;
        }
        puts(prev==0?"Yes":"No");
    }
    return 0;
}
