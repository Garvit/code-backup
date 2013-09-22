#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
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
long long int students[100000];
long long int price[100000];
int main()
{
    long long int n,i,ans;
    while((n=scan())!=0)
    {
        ans=0;
        for(i=0;i<n;i++)
        {
            students[i]=scan();
        }
        for(i=0;i<n;i++)
        {
            price[i]=scan();
        }
        sort(students,students+n);
        sort(price,price+n);
        for(i=0;i<n;i++)
        {
            //printf("%lld %lld\n",price[i],students[n-1-i]);
            ans+=price[i]*students[n-1-i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
