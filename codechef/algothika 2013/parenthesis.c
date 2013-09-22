#include<stdio.h>
#include<string.h>
int arr[35];
void eval()
{
    arr[1]=1;
    arr[2]=1;
    int i,j;
    for(i=3;i<=34;i++)
    {
        for(j=1;j<i;j++)
        {
            arr[i]+=(arr[i-j]*arr[j]);
        }
    }
}

int main()
{
    int t,n;
    char str[40];
    scanf("%d",&t);
    eval();
    while(t--)
    {
        scanf("%s",str);
        n=strlen(str);
        printf("%d\n",arr[n]);
    }
    return 0;
}
