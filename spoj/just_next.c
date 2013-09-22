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
char digits[1000010];
int main()
{
    int t,n,i,flag,j;
    char d,d1;
    t=scan();
    while(t--)
    {
        n=scan(); flag=0;
        for(i=0;i<n;i++)
        {
            digits[i]=getchar();
            getchar();
        }

        for(i=n-1;i>0;i--)
        {
            if(digits[i]>digits[i-1])
            {
                for(j=i;j<n;j++)
                {
                    if(j+1 < n && digits[j+1]<=digits[i-1])
                    {
                        d=digits[i-1];
                        digits[i-1]=digits[j];
                        digits[j]=d;
                        break;
                    }
                }
                if(j==n)
                {
                    d=digits[i-1];
                    digits[i-1]=digits[n-1];
                    digits[n-1]=d;
                }
                break;
            }
            //printf("%c\n",d);

        }
        if(i==0)
        {
            printf("-1\n");
        }
        else
        {
            for(j=0;j<i;j++)
            {
                printf("%c",digits[j]);
            }
            for(j=n-1;j>=i;j--)
            {
                printf("%c",digits[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
