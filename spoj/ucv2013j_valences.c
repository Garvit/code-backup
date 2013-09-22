#include<stdio.h>
#include<math.h>
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
    int n,i,ans,take,num;
    n=scan();
    while(n!=0)
    {
        if(n&1)
            take=(n+1)/2;
        else
            take=n/2;
        ans=0;
        for(i=0;i<n;i++)
        {
            num=scan();
            if(i>=n-take)
                ans+=num;
        }
        printf("%d\n",ans);
        n=scan();
    }
    return 0;
}
