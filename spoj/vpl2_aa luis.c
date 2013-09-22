#include<stdio.h>
#include<math.h>

int main()
{
    int n,i,i1,t,r,z;
    scanf("%d",&n);
    for(z=1;z<=n;z++)
    {
        scanf("%d %d %d %d",&i,&i1,&t,&r);
        double num=log(r*1.0/i);
        double den=log(i1*1.0/i);
        double ans=t*num/den;
        printf("Scenario #%d: %.2lf\n",z,ans);
    }
    return 0;
}
