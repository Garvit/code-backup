#include<stdio.h>

long long int inline scan()
{
    long long int N = 0;
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
    int t,k,i;
    long long int n;
    char str[60];
    char arr[]={'6','5'};
    t=scan();
    while(t--)
    {
        k=0;
        n=scan();
        while(n>0){
        str[k++]=arr[n%2];
        n=(n-1)/2;
        }
        for(i=k-1;i>=0;i--)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}

