#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 1000000
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
bool pr[MAX];
int arr[MAX+1];
void sieve()
{
    int start=2,i,limit=ceil(sqrt(MAX));
    arr[1]=1;arr[2]=1;arr[3]=2;
    while(1)
    {
        for(i=2*start;i<=MAX;i+=(start))
        {
            pr[i]=1;
            if(arr[i]==0)
            {
                arr[i]=i-i/start;
            }
            else
            {
                arr[i]=arr[i]-arr[i]/start;
            }

        }
        start++;
        for(i=start;i<=MAX;i++)
        {
            if(pr[i]==0)
            {
                arr[i]=i-1;
                break;
            }
        }
        if(i>MAX)
            break;
        start=i;
    }
}

int main()
{
    int i,t,n;
    sieve();
    t=scan();
    while(t--)
    {
        n=scan();
        printf("%d\n",arr[n]);
    }
    return 0;
}
