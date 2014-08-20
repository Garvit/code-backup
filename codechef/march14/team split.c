#include<stdio.h>
#include<stdbool.h>

bool arr[1000000];

int main()
{
    int t,n,a,b,c,d,i,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
        long long s=d;
        arr[s]=!arr[s];
        for(i=1;i<n;i++)
        {
            s=(a*s*s+b*s+c)%1000000;
            arr[s]=!arr[s];
            //printf("%lld ",s);
        }
        bool flag=true;
        ans=0;
        for(i=999999;i>=1;i--)
        {
            if(arr[i])
            {
                if(flag) ans+=i;
                else ans-=i;
                flag=!flag;
                arr[i]=false;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
