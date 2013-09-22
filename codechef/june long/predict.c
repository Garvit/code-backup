#include<stdio.h>

int main()
{
    int t,i;
    double pa,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=10000;
        scanf("%lf",&pa);
        pa=pa>0.5?pa:(1-pa);
        ans+=(1-pa)*10000*(2*pa-1);
        printf("%lf\n",ans);
    }
    return 0;
}
