#include<stdio.h>
int arr[100000];
int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}
int main()
{
    int i,n,t,ans;
    t=scan();
    while(t--)
    {
        n=scan();
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        ans=arr[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(arr[i]>ans) ans=arr[i];
            else ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
