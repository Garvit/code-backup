#include<stdio.h>

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
    int arr[100];
    int t,n,i;
    t=scan();
    while(t--)
    {
        n=scan();
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        if(n&1)
            printf("YES\n");
        else{
        for(i=1;i<n-1;i++)
        {
                if(arr[i]<arr[i-1])
                {
                    arr[i+1]+=arr[i-1]-arr[i];
                    arr[i]=arr[i-1];
                }
                else
                {
                    if(i&1)
                    {
                        arr[n-1]+=arr[i]-arr[i-1];
                    }
                }
        }
        if(arr[n-1]!=arr[n-2]) printf("NO\n");
        else printf("YES\n");
        }
    }
    return 0;
}
