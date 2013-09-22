#include<stdio.h>
int arr[50];
int eval(int n)
{
    if(arr[n]) return arr[n];
    if(n==0) return 1;
    if(n==1) return 3;
    int sum=0,i;
    for(i=n-2;i>=0;i--)
    {
        sum+=eval(i);
    }
    sum++;
    sum*=2;
    arr[n]=eval(n-1)+sum;
    return arr[n];
}

int main()
{
    int n,a=3,b=7,ans;
    scanf("%d",&n);
    printf("%d\n",eval(n));
    return 0;
}
