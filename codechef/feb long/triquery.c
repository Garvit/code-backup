#include<stdio.h>
#include<stdbool.h>
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
int cox[300001];
int coy[300001];
int main()
{
    int n,q,x,y,d,i,count=0,j;
    bool flag1,flag2,flag3;
    n=scan();
    q=scan();
    for(i=0;i<n;i++)
    {
        cox[i]=scan();
        coy[i]=scan();

    }
    for(i=0;i<q;i++)
    {

        count=0;
        x=scan();
        y=scan();
        d=scan();
        for(j=0;j<n;j++)
        {
            flag1=flag2=flag3=0;
            //printf("%d %d\n",x,y);
            if(cox[j]-x>=0) flag1=1;


            if(coy[j]-y>=0) flag2=1;


            if(coy[j]+cox[j]-x-y-d<=0) flag3=1;

            if(flag1 && flag2 && flag3){ count++; }

        }
        printf("%d\n",count);
    }

}
