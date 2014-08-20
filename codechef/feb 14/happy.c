#include<stdio.h>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define getchar getchar_unlocked
int pos[1000001];
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
int main()
{
    int n,k,i,num;
    n=scan();
    k=scan();
    for(i=1;i<=n;i++)
    {
        num=scan();
        int p=i<(n+1-i)?i:(n+1-i);
        if(pos[num]==0) pos[num]=p;
        else if(pos[num]>p) pos[num]=p;
    }
    int ans=-1;
    for(i=1;i<(k+1)/2;i++)
    {
        if(pos[i]!=0 && pos[k-i]!=0)
        {
            int p=MAX(pos[i],pos[k-i]);
            if(ans==-1)
                ans=p;
            else
                ans=MIN(ans,p);
        }
    }
    printf("%d",ans);
    return 0;
}
