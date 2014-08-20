#include<stdio.h>

long long tree[1000001];
int max;
void update(int x,int val)
{
    x++;
    while(x<=max)
    {
        tree[x]+=val;
        x+=(x & -x);
    }
}
long long query(int x)
{
    x++;
    long long sum=0;
    while(x>0)
    {
        sum+=tree[x];
        x-=(x&-x);
    }
    return sum;
}
int main()
{
    int n,q,i,num,x,y;
    scanf("%d %d",&n,&q);
    max=n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        update(i,num);
    }
    /*for(i=1;i<=n;i++)
        printf("%lld ",tree[i]);
    printf("\n");*/
    for(i=0;i<q;i++)
    {
        getchar();
        char c=getchar();
        scanf("%d %d",&x,&y);
        if(c=='S')
            printf("%lld\n",query(y)-query(x-1));
        else if(c=='G')
            update(x,y);
        else if(c=='T')
            update(x,-y);
    }
    return 0;
}
