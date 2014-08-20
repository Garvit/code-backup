#include<stdio.h>

int tree[101][101][101];
int arr[101][101][101];
int n;
void update(int x,int y,int z,int val)
{
    printf("for %d %d %d\n",x,y,z);
    int i,j,k;
    for(i=x;i<=n;i+=(i&-i)){
        for(j=y;j<=n;j+=(j&-j)){
            for(k=z;k<=n;k+=(k&-k)){
                tree[i][j][k]+=val;
                printf("%d %d %d\n",i,j,k);
                }
            }
        }
}
int query(int x,int y,int z)
{
    int sum=0,i,j,k;
    for(i=x;i>0;i-=(i&-i)){
        for(j=y;j>0;j-=(j&-j)){
            for(k=z;k>0;k-=(k&-k)){
                sum+=tree[i][j][k];}}}

    return sum;
}
int range(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return query(x2,y2,z2)-query(x2,y2,z1-1)-query(x2,y1-1,z2)-query(x1-1,y2,z2)
            +query(x2,y1-1,z1-1)+query(x1-1,y2,z1-1)+query(x1-1,y1-1,z2)
            -query(x1-1,y1-1,z1-1);
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf("%d",&arr[i][j][k]);
                update(i+1,j+1,k+1,arr[i][j][k]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                printf("%d ",arr[i][j][k]);
            }
        }
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                printf("%d ",query(i,j,k));
            }
        }
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        int x1,y1,z1,x2,y2,z2;
        scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
        printf("%d\n",range(x1,y1,z1,x2,y2,z2));
    }
}

