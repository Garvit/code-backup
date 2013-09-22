#include<stdio.h>
#include<stdbool.h>
int a[300][300];
bool b1[300];
bool b2[300];
int main()
{
    int h,w,i,j,k,x,y,rcount=0,ccount=0,total,f;
    long long sum=0,sum1=0;
    scanf("%d",&h);
    scanf("%d",&w);
    k=0;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            scanf("%d",&a[i][j]);
                    }
    }
    for(i=0;i<h;i++)
    {
        b1[i]=1;
        rcount++;
    }
    for(i=0;i<w;i++)
    {
        b2[i]=1;
        ccount++;
    }


    for(i=0;i<h;i++)
    {
        sum=0;
        if(b1[i])
        {
            for(j=0;j<w;j++)
            {
                if(b2[j])
                    sum+=a[i][j];
            }
            if(sum<0){
                b1[i]=0;
                rcount--;
                for(x=0;x<w;x++)
        {
        sum1=0;
        if(b2[x])
        {
            for(y=0;y<h;y++)
            {
                if(b1[y])
                    sum1+=a[y][x];
            }
            if(sum1<0){
                b2[x]=0;
                ccount--;
            }
        }
        }
            }
        }
    }
    for(i=0;i<w;i++)
    {
        sum=0;
        if(b2[i])
        {
            for(j=0;j<h;j++)
            {
                if(b1[j])
                    sum+=a[j][i];
            }
            if(sum<0){
                b2[i]=0;
                ccount--;
                for(x=0;x<h;x++)
        {
        sum1=0;
        if(b1[x])
        {
            for(y=0;y<w;y++)
            {
                if(b2[y])
                    sum1+=a[x][y];
            }
            if(sum1<0){
                b1[x]=0;
                rcount--;
            }
        }
        }
            }
        }
    }

    printf("%d %d\n",rcount,ccount);
    for(i=0;i<h;i++)
    {
        if(b1[i])
            printf("%d ",i);
    }
    printf("\n");
    for(i=0;i<w;i++)
    {
        if(b2[i])
            printf("%d ",i);
    }
    return 0;
}
