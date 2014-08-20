#include<stdio.h>
#include<stdbool.h>
#define ll long long

bool func(ll p,int y,ll mid)
{
    //printf("%d %lld %lld \n",y,mid,p);
    if(y==0) return true;

    if(p>mid) return func(p-mid,y-1,mid/2);
    else return !func(p,y-1,mid/2);
}
int main()
{
    long long mid=1,p;
    int y,i;
    scanf("%d",&y);
    scanf("%lld",&p);
    //printf("%lld\n",p);
    for(i=1;i<y;i++)
        mid*=2;
    //printf("%lld %lld\n",mid,p);
    if(func(p,y,mid)) printf("red");
    else printf("blue");
    return 0;
}
