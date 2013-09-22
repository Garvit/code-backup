#include<stdio.h>

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
int hcf(int a,int b)
{
    int rem=a%b;
    while(rem!=0)
    {
        a=b;
        b=rem;
        rem=a%b;
    }
    return b;

}
int main()
{
    int t,x,y,z,max,min,gcd;
    t=scan();
    while(t--)
    {
        x=scan();
        y=scan();
        z=scan();
        max=x>y?x:y;
        min=x>y?y:x;
        if(z>max)
        {
            printf("NO\n");
        }

        else
        {
            gcd=hcf(max,min);
            printf("%d\n",gcd);
            if(z%gcd==0)
            {
                printf("YES\n");
            }
            else
                printf("NO\n");
        }


    }
    return 0;
}
