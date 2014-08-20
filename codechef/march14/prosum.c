#include<stdio.h>
#define getchar getchar_unlocked
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
    int i,t,n,count2,count3;
    long long ans;
    t=scan();
    while(t--)
    {
        n=scan();
        ans=0;
        count2=0;count3=0;
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
            if(arr[i]>2){
                count3++;
                count2++;
            }
            else if(arr[i]==2) count2++;
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]>2)
            {
                count3--;count2--;
                ans+=count2;
            }
            else if(arr[i]==2)
            {
                count2--;
                ans+=count3;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
