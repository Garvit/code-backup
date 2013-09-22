#include<stdio.h>
#include<math.h>

int main()
{
    int t,l,w,ans,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&w);
        if(l>=w)
        {
            printf("1\n");
        }
        else
        {
            n=ceil(2.0*w/l);
            ans=n*(n-1)+1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
