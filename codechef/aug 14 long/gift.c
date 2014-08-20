#include<stdio.h>

int main()
{
    int t,i,k,n,num,even=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        even=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            if (num%2==0) ++even;
        }
        if ((k==0 && even<n) || (k!=0 && k<=even)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
