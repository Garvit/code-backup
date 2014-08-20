#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define ll long long
ll inline scan()
{
    ll N = 0;
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
bool check(long long num)
{
    int d;
    while(num>0)
    {
        d=num%10;
        if(d!=0 && d!=4 && d!=9 && d!=1)
            return false;
        num/=10;
    }
    return true;
}
short int count[100001];
int main()
{
    int t;
    ll a,b,i;
    count[1]=1;
    for(i=2;i<=100000;i++)
    {
        count[i]=count[i-1];
        if(check(i*i)) count[i]++;
    }

    t=scan();
    while(t--)
    {
        a=scan();
        b=scan();
        int r1=sqrt(a);
        int r2=sqrt(b);
        int ans=count[r2]-count[r1];
        if((ll)r1*r1==a && check(a)) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
