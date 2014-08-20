#include<stdio.h>

int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int n,m,i,j,a,b,ans=-1,x,y,an,flag=0;
    scanf("%d %d %d %d %d %d",&n,&m,&i,&j,&a,&b);
    x=i-1;y=j-1;
    if(((i-1)>=a || (n-i)>=a) && ((j-1)>=b || (m-j)>=b))
        flag=1;

    if(x%a==0 && y%b==0 && (x/a-y/b)%2==0)
    {
        an=max(x/a,y/b);
        if(ans==-1) ans=an;
        else ans=min(ans,an);
    }
    x=i-1;y=m-j;
    if(x%a==0 && y%b==0 && (x/a-y/b)%2==0)
    {
        an=max(x/a,y/b);
        if(ans==-1) ans=an;
        else ans=min(ans,an);
    }
    x=n-i;y=j-1;
    if(x%a==0 && y%b==0 && (x/a-y/b)%2==0)
    {
        an=max(x/a,y/b);
        if(ans==-1) ans=an;
        else ans=min(ans,an);
    }
    x=n-i;y=m-j;
    if(x%a==0 && y%b==0 && (x/a-y/b)%2==0)
    {
        an=max(x/a,y/b);
        if(ans==-1) ans=an;
        else ans=min(ans,an);
    }
    if(ans==-1 || (ans!=0 && flag==0)) printf("Poor Inna and pony!");
    else printf("%d",ans);
    return 0;
}
