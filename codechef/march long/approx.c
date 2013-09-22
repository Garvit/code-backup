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
short mem[60];
char str[60];
void eval(int x,int y,int k)
{
    int i;
    mem[0]=x/y;
    x=(x%y)*10;
    for(i=1;i<k;i++)
    {
        mem[i]=x/y;
        str[i-1]=mem[i]+'0';
        x=(x%y)*10;
    }
    str[k-1]='\0';
}
int main()
{
    int t,k,i,times;
    t=scan();
    eval(46870,33102,52);
    while(t--)
    {
        k=scan();
        printf("3");
        if(k!=0)
        {
            printf(".");
            printf("%d",mem[0]);
            times=(k-1)/51;
            for(i=0;i<times;i++)
            {
                printf("%s",str);
            }
            for(i=0;i<(k-1)%51;i++)
            {
                printf("%d",mem[i+1]);
            }
        }
        printf("\n");
    }
    return 0;
}
