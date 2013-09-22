#include<stdio.h>
#include<string.h>

char *str="zyxwvutsrqponmlkjihgfedcba";
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
    int t,k,d,m;
    t=scan();
    while(t--)
    {
        k=scan();
        d=k/25;
        m=k%25;
        if(m)
        while(m>=0)
        {
            printf("%c",m--+97);
        }


        while(d--)
        {
            printf("%s",str);
        }
        printf("\n");
    }
    return 0;
}
