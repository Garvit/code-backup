#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
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

int arr[100000];
int main()
{
    int t,n,i,med,count,max=0;
    t=scan();
    while(t--)
    {
        count=1;
        max=0;
        n=scan();
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        sort(arr,arr+n);
        for(i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1]) count++;
            else
            {
                if(count>max)
                    max=count;

                count=1;
            }

        }
        if(count>max)
            max=count;
        if(max>n/2+1) printf("0\n");
        else printf("%d\n",(n/2+1-max));

    }
    return 0;
}
