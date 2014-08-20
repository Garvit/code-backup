#include<stdio.h>
#define min(a,b) (a<b?a:b)
int arr[1001];


void func()
{
    int i,j;
    for(i=1;i<=1000;i++)
    {
        arr[i]=1+arr[i-1];
        for(j=2;j<32;j++)
        {
            if(i-j*j < 0) break;
            arr[i]=min(arr[i],1+arr[i-j*j]);
        }
    }
}
int main()
{
    int t,i,a;
    scanf("%d",&t);
    func();
    while(t--)
    {
        scanf("%d",&a);
        printf("%d\n",arr[a]);
    }
}
