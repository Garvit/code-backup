#include<stdio.h>

int arr[101];
int main()
{
    int n,m,i,a,b,c,ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        arr[a]-=c;
        arr[b]+=c;
    }
    for(i=1;i<=n;i++)
    {
        if(arr[i]>0) ans+=arr[i];
    }
    printf("%d",ans);
    return 0;
}
