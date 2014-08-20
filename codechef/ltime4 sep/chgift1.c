#include<stdio.h>
#define ll long long
int arr[11];

int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        ll mx,mn,newmx,newmn;
        mx=mn=arr[0];
        for(i=1;i<n;i++)
        {
            newmn=mn+arr[i];
            newmx=mx+arr[i];

            newmn=min(newmn,mn+arr[i]);
            newmn=min(newmn,mx+arr[i]);
            newmn=min(newmn,mn-arr[i]);
            newmn=min(newmn,mx-arr[i]);
            newmn=min(newmn,mn*arr[i]);
            newmn=min(newmn,mx*arr[i]);

            newmx=min(newmx,mn+arr[i]);
            newmx=min(newmx,mx+arr[i]);
            newmx=min(newmx,mn-arr[i]);
            newmx=min(newmx,mx-arr[i]);
            newmx=min(newmx,mn*arr[i]);
            newmx=min(newmx,mx*arr[i]);

            mx=newmx;
            mn=newmn;
        }
        printf("%lld\n",mn);

    }
    return 0;
}
