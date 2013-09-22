#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[4000];
int dprimes[4000],num=0;
void sieve()
{
    int start=2,i;

    while(1)
    {
        for(i=start*2;i<4000;i+=start)
        {
            arr[i]++;
            if(arr[i]==3)
            {
                dprimes[num++]=i;

            }

        }
        start++;
        for(i=start;i<4000;i++)
        {
            if(arr[i]==0)
            {
                break;
            }
        }
        if(i>=4000)
            break;
        start=i;
    }
}

int main()
{
    sieve();
    sort(dprimes,dprimes+num);
    //printf("%d %d %d",dprimes[0],dprimes[1],dprimes[999]);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",dprimes[n-1]);
    }
    return 0;
}

