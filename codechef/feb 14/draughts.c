#include<stdio.h>
#include<stdbool.h>
bool window[50001];
int grp[50001];
int parent[50001];
int total[50001];
bool dt[50001];
int findgrp(int n)
{
    int i=n;
    while(grp[i]!=i)
    {
        i=grp[i];
    }
    grp[n]=i;
    return i;
}
int main()
{
    int n,m,i,b,x,y,g1,g2,fans=0,rans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&b);
        window[i]=b;
        grp[i]=i;
        parent[i]=i;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        g1=findgrp(x);
        g2=findgrp(y);
        if(window[g1]==1){
            grp[g2]=g1;
            parent[y]
        }

        grp[g1]=g2;
    }
    for(i=1;i<=n;i++)
    {
        g1=findgrp(i);
        printf("%d ",g1);
        if(window[i]==1)
            total[g1]++;
    }
    for(i=1;i<=n;i++)
    {
        fans+=total[i]*(total[i]-1)/2;
    }
    for(i=1;i<=n;i++)
    {
        if(dt[i]==1) continue;
        if(window[i]==1)
        {
            dt[i]=1;
            while(i!=grp[i])
            {
                pa
            }
        }
    }
    printf("%d ",fans);
    return 0;
}
