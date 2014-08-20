#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,a;
    long long ans=1;
    scanf("%d %d %d",&n,&m,&a);
    ans=ceil((double)n/a)*ceil((double)m/a);
    printf("%I64d",ans);
    return 0;
}
