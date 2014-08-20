#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
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
long long llabs(long long a)
{
    return a<0?-a:a;
}
int main()
{
    int n;
    n=scan();
    int* arr = new int[n];
    long long sum1=0,sum2=0;
    //vector<pair<int,int> > shifts;
    for(int i=0;i<n/2;++i)
    {
        arr[i]=scan();
        sum1+=arr[i];
    }
    for(int i=n/2;i<n;++i)
    {
        arr[i]=scan();
        sum2+=arr[i];
    }

    if(sum1==sum2){ printf("0");
        return 0;
    }
    long long diff=llabs(sum1-sum2);
    long long min_diff=diff,curr;
    int pos1,pos2;
    for(int  i=n/2-1;i>=0;--i)
    {
        for(int j=n/2;j<n;++j)
        {
            curr=llabs(sum1-2*(arr[i]-arr[j])-sum2);
            if(curr<min_diff)
            {
                min_diff=curr;
                pos1=i+1;
                pos2=j+1;
            }
        }
    }
    int shifts=pos2-n/2;
    printf("%d\n",shifts);
    printf("%d %d\n",pos1,pos2);
    for(int i=pos2-1;i>n/2;--i)
    {
        printf("%d %d\n",n/2,i);
    }
    return 0;
}
