#include<stdio.h>

int place[1000];

int func(int i,int j)
{
    //printf("func call %d %d\n",i,j);
    if(i>j) return 0;
    if(i==j)
    {
        if(place[i]<1) return place[i];
        else return 1;
    }
    int num,cost,k,n1,n2,c,p=-1;
    num=j-i+1;
    cost=(num*(num+1))/2;
    for(k=i;k<=j;k++)
    {
        n1=k-i;n2=j-k;
        c=place[k]+(n1*(n1+1))/2+(n2*(n2+1))/2;
        if(c<cost)
        {
            cost=c;
            p=k;
        }
    }
    //printf("%d %d\n",cost,p);
    if(p==-1) return cost;
    else return place[p]+func(i,p-1)+func(p+1,j);
}
int main()
{
    int n,i,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&place[i]);
    }
    ans=place[n-1]+func(0,n-2);
    printf("%d",ans);
    return 0;
}
