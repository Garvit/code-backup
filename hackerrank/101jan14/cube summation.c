#include<stdio.h>
#include<stdlib.h>

long long tree[101][101][101];
int arr[101][101][101];
int n;
void update(int x,int y,int z,int val)
{
    int i,j,k;
    for(i=x;i<=n;i+=(i&-i)){
        for(j=y;j<=n;j+=(j&-j)){
            for(k=z;k<=n;k+=(k&-k)){
                tree[i][j][k]+=val;
                }
            }
        }
}
long long query(int x,int y,int z)
{
    long long sum=0,i,j,k;
    for(i=x;i>0;i-=(i&-i)){
        for(j=y;j>0;j-=(j&-j)){
            for(k=z;k>0;k-=(k&-k)){
                sum+=tree[i][j][k];}}}

    return sum;
}
long long range(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return query(x2,y2,z2)-query(x2,y2,z1-1)-query(x2,y1-1,z2)-query(x1-1,y2,z2)
            +query(x2,y1-1,z1-1)+query(x1-1,y2,z1-1)+query(x1-1,y1-1,z2)
            -query(x1-1,y1-1,z1-1);
}
int main()
{
    int i,t,m;
    char type[10];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        memset(tree,0,sizeof(tree));
        memset(arr,0,sizeof(arr));
        for(i=0;i<m;i++)
        {
            scanf("%s",type);
            if(type[0]=='U')
            {
                int x,y,z,val;
                scanf("%d %d %d %d",&x,&y,&z,&val);
                update(x,y,z,-arr[x][y][z]);
                update(x,y,z,val);
                arr[x][y][z]=val;
            }
            else
            {
                int x1,y1,z1,x2,y2,z2;
                scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
                printf("%lld\n",range(x1,y1,z1,x2,y2,z2));
            }

        }

     }
}

