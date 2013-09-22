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
int arr[1001];
int main()
{
    int t,n,r,z,flag=0,i,j;
    t=scan();
    for(z=1;z<=t;z++)
    {
        n=scan();
        r=scan();
        flag=0;
        while(r--)
        {
            i=scan();
            j=scan();
            if(arr[i]==2){ flag=1;}
            if(arr[j]==1) { flag=1;}

            arr[i]=1;arr[j]=2;
        }
        if(flag==1)
        {
            printf("Scenario #%d: spied\n",z);
        }
        else
        {
            printf("Scenario #%d: spying\n",z);
        }
        memset(arr,0,sizeof(arr));

    }
    return 0;
}
