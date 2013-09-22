#include<stdio.h>
#define getchar getchar_unlocked
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
    int t,n,row,diff;
    char dir,seat;
    char s[]={'W','M','A','A','W'};
    t=scan();
    while(t--)
    {
        n=scan();
        if(n==1)
            printf("poor conductor\n");
        else
        {
            row=(n-2)/5 + 1;
            if(row%2==0)
                diff=n-5*(row-1)-1;
            else
                diff=5*row+2-n;

            if(diff<=3) dir='R';
            else dir='L';

            seat=s[diff-1];
            printf("%d %c %c\n",row,seat,dir);
        }

    }
    return 0;
}
