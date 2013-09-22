#include<stdio.h>

int main()
{
    int t,d,ds,dt,max,min;
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&ds,&dt,&d);
        if(ds+dt <= d)
        {
            ans=d-(ds+dt);
        }
        else
        {
            max=ds>dt?ds:dt;
            min=ds<dt?ds:dt;
            if(d+min > max)
            {
                ans=0.0;
            }
            else
            {
                ans=max-(d+min);
            }
        }
        printf("%f\n",ans);
    }
}
