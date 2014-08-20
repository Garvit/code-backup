#include <stdio.h>

int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1;C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}

int main()
{
    int t,x,y;
    t=scan();
    while(t--)
    {
        x=scan();
        y=scan();
        if ((x>0 && x%2 && y>=-(x-1) && y<=x+1) ||
            (x<=0 && x%2==0 && y>=x && y<=-x) ||
            (y>=0 && y%2==0 && x>=-y && x<=y-1) ||
            (y<0 && y%2==0 && x>=y && x<=-y+1)) {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
