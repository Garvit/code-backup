#include<stdio.h>
#include<stdbool.h>


bool check(int n)
{
    while(n>0)
    {
        short int d=n%10;
        if(d==4 || d==7) return 1;
        n=n/10;
    }
    return 0;
}

int main()
{
    int t,n,ans,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=check(n);
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                ans+=check(i);
                if(i!=n/i)
                    ans+=check(n/i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
