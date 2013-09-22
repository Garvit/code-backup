#include<stdio.h>
int arr[100];
int eval(int n)
{
    if(arr[n]) return arr[n];
    if(n==0) return 1;
    if(n==1) return 2;

    arr[n]=eval(n-1)+eval(n-2);
}

int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",eval(n));
    }

    return 0;
}
