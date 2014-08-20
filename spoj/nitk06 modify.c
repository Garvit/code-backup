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
    int t,n,i;
    int arr[10000];
    t=scan();
    while(t--)
    {
        n=scan();
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        for(i=0;i<n-1;i++)
        {
            arr[i+1]-=arr[i];
            if(arr[i+1]<0) break;
        }
        if(i!=n-1 || arr[n-1]!=0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
