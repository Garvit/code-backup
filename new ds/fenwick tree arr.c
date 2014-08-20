#include<stdio.h>

int tree[101];
int arr[101];
void update(int i,int val)
{
    for(;i<=100;i+=(i&-i))
        tree[i]+=val;
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
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        update(i+1,arr[i]);
    }
    for(i=0;i<5;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",range(a,b));
    }
}
