#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int *s=new int[n];
        int *a=new int[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=n-1;i>=0;i--)
        {
            if(s[i]<=a[i])
            {
                printf("NO\n");
                break;
            }
        }
        if(i<0) printf("YES\n");

    }
    return 0;
}
