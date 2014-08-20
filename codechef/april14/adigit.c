#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int arr[10];
int ans[100000];
int main()
{
    int n,m,i,d,x,j;
    scanf("%d %d",&n,&m);
    char str[100010];
    scanf("%s",str);
    for(i=0;i<n;i++)
    {
        d=str[i]-'0';
        for(j=0;j<10;j++)
        {
            ans[i]+=arr[j]*abs(j-d);
        }
       // printf("%d\n",ans[i]);
        arr[d]++;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x-1]);
    }
    return 0;
}
