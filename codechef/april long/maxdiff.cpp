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
int w[110];
int main()
{
    int t,n,k,sum1=0,sum2=0,diff1,diff2;
    t=scan();
    while(t--)
    {
        sum1=0;sum2=0;
        n=scan();
        k=scan();
        for(int i=0;i<n;i++)
        {
            w[i]=scan();

        }
        sort(w,w+n);
        for(int i=0;i<k;i++)
        {
            sum1+=w[i];
        }
        for(int i=k;i<n;i++)
        {
            sum2+=w[i];
        }
        diff1=sum1>sum2?(sum1-sum2):(sum2-sum1);
        sum1=0;sum2=0;
        for(int i=0;i<k;i++)
        {
            sum1+=w[n-1-i];
        }
        for(int i=k;i<n;i++)
        {
            sum2+=w[n-1-i];
        }
        diff2=sum1>sum2?(sum1-sum2):(sum2-sum1);

        printf("%d\n",(diff1>diff2?diff1:diff2));
    }
    return 0;
}

