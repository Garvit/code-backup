#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
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
bool pr[10000001];
int arr[10000001];
void sieve()
{
    int start=3,i,limit=sqrt(10000000),count=2;
    arr[2]=1;
    arr[3]=2;

    while(1)
    {
        //printf("\n%d\n",start);
        for(i=3*start;i<10000000;i+=(2*start))
        {
            pr[i]=1;
            //printf("%d ",i);
        }
        start++;
        for(i=start;i<limit;i++)
        {
            if(i%2!=0 && pr[i]==0)
            {
                arr[i]=arr[i-1]+1;
                break;
            }
            else
            {
                arr[i]=arr[i-1];
            }
        }
        if(i>=limit)
            break;
        start=i;
    }
}
int main()
{
    int num,n,m,t,start,count,i,limit=sqrt(10000000);
    t=scan();
    sieve();

    for(i=limit;i<=10000000;i++)
    {
        if(i%2!=0 && pr[i]==0)
            {
                arr[i]=arr[i-1]+1;

            }
            else
            {

                arr[i]=arr[i-1];
            }
    }
    //printf("%d %d %d %d",limit,arr[limit-1],arr[limit],arr[10000000]);
    while(t--){
    num=scan();
    count=0;
    count=arr[num]-arr[num/2];
    printf("%d\n",count);
        //memset(arr,0,sizeof(arr));
    }
    return 0;
}
