#include<stdio.h>
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
int tree[1000001];
int arr[1000001];
void update(int i)
{
    for(;i<=100;i+=(i&-i))
        tree[i]++;
}
int query(int i)
{
    int sum=0;
    for(;i>0;i-=(i&-i))
        sum+=tree[i];

    return sum;
}
int range(int a,int b)
{
    return query(b)-query(a-1);
}
int main()
{
    int n,i;
    long long rank1=0,rank2=0;
    n=scan();
    for(i=0;i<n;i++)
    {
        arr[i]=scan();
        update(arr[i]);
        rank1+=query(arr[i]-1);
    }
    memset(tree,0,sizeof(tree));
    for(i=0;i<n;i++)
    {
        arr[i]=scan();
        update(arr[i]);
        rank2+=query(arr[i]-1);
    }
    if(rank1>rank2)
        printf("Upendra %lld",rank1);
    else
        printf("Ujjaval %lld",rank2);
}

