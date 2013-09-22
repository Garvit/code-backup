#include<stdio.h>
#include<string.h>
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
int arr[51][1001];
int w[51];
int v[51];
int knapsack(int i,int k)
{
    if(i==-1 || k==0) return 0;
    if(arr[i][k]) return arr[i][k];

    if(w[i]>k)
    {
        arr[i][k]=knapsack(i-1,k);
    }
    else
    {
        int t1=v[i]+knapsack(i-1,k-w[i]);
        int t2=knapsack(i-1,k);
        arr[i][k]=t1>t2?t1:t2;
    }
    return arr[i][k];

}
int main()
{
    int n,k,m,i;
    n=scan();
    while(n--)
    {
        k=scan();
        m=scan();
        for(i=0;i<m;i++)
        {
            w[i]=scan();
            v[i]=scan();
        }
        int ans=knapsack(m-1,k);
        printf("Hey stupid robber, you can get %d.\n",ans);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
