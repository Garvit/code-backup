#include<stdio.h>
#include<stdbool.h>
int a[300][300];
bool b1[300];
bool b2[300];
bool maxb1[300];
bool maxb2[300];
bool visit[90000];
int temp[90000];
int indexi[90000];
int indexj[90000];
void swap(int i,int j)
{
    int temp1=temp[i];
    temp[i]=temp[j];
    temp[j]=temp1;

    int temp2=indexi[i];
    indexi[i]=indexi[j];
    indexi[j]=temp2;

    int temp3=indexj[i];
    indexj[i]=indexj[j];
    indexj[j]=temp3;

}
void quicksort(int start,int end)
{
    if(start>=end)
        return;

    int s=start,i;
    for(i=start;i<end;i++)
    {
        if(temp[i]<temp[end])
        {
            swap(i,s);
            s++;
        }
    }
    swap(s,end);
    quicksort(start,s-1);
    quicksort(s+1,end);
    return;
}
int main()
{
    int h,w,i,j,x,y,k,rcount=0,ccount=0,total,f,maxrcount,maxccount;
    long long sum=0,totalsum=0,maxsum=0,sum1=0;
    scanf("%d",&h);
    scanf("%d",&w);
    k=0;
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            scanf("%d",&a[i][j]);
            temp[k]=a[i][j];
            indexi[k]=i;
            indexj[k]=j;
            k++;
        }
    }
    total=k;
    /*for(i=0;i<total;i++)
        printf("%d\n",temp[i]);
    */quicksort(0,total-1);
    int l=total-1,l1;
    while(temp[l]>0){
        if(visit[l])
        {
            l--;
            continue;
        }
        for(l1=0;l1<300;l1++){
            b1[l1]=0;
            b2[l1]=0;
        }
        totalsum=temp[l];
        rcount=1;
        ccount=1;
        b1[indexi[l]]=1;
        b2[indexj[l]]=1;
        visit[l]=1;
    for(f=total-1;f>=0;f--)
    {
        i=indexi[f];
        j=indexj[f];
            if((!(b1[i]) || !(b2[j])) && a[i][j]>0)
            {
                if(b1[i])
                {
                    sum=0;
                    for(k=0;k<h;k++)
                    {
                        if(b1[k])
                            sum+=a[k][j];
                    }
                    if(sum>0){
                        b2[j]=1;
                        ccount++;
                        totalsum+=sum;
                        visit[f]=1;
                    }
                }
                else if(b2[j])
                {
                    sum=0;
                    for(k=0;k<w;k++)
                    {
                        if(b2[k])
                            sum+=a[i][k];
                    }
                    if(sum>0){
                        b1[i]=1;
                        rcount++;
                        totalsum+=sum;
                        visit[f]=1;
                    }
                }
                else
                {
                    sum=0;
                    for(k=0;k<h;k++)
                    {
                        if(b1[k] || k==i)
                            sum+=a[k][j];
                    }
                    for(k=0;k<w;k++)
                    {
                        if(b2[k])
                            sum+=a[i][k];
                    }
                    if(sum>0)
                    {
                        b1[i]=1;
                        b2[j]=1;
                        rcount++;
                        ccount++;
                        totalsum+=sum;
                        visit[f]=1;
                    }

                }
            }

    }
    if(totalsum>maxsum)
    {
        maxsum=totalsum;
        maxrcount=rcount;
        maxccount=ccount;
        for(l1=0;l1<h;l1++){
            maxb1[l1]=b1[l1];
        }
        for(l1=0;l1<w;l1++){
            maxb2[l1]=b2[l1];
        }
    }
    l--;
    }
    for(i=0;i<h;i++)
    {
        sum=0;
        if(maxb1[i])
        {
            for(j=0;j<w;j++)
            {
                if(maxb2[j])
                    sum+=a[i][j];
            }
            if(sum<0){
                maxb1[i]=0;
                maxrcount--;
                for(x=0;x<w;x++)
        {
        sum1=0;
        if(maxb2[x])
        {
            for(y=0;y<h;y++)
            {
                if(maxb1[y])
                    sum1+=a[y][x];
            }
            if(sum1<0){
                maxb2[x]=0;
                maxccount--;
            }
        }
        }
            }
        }
    }
    for(i=0;i<w;i++)
    {
        sum=0;
        if(maxb2[i])
        {
            for(j=0;j<h;j++)
            {
                if(maxb1[j])
                    sum+=a[j][i];
            }
            if(sum<0){
                maxb2[i]=0;
                maxccount--;
                for(x=0;x<h;x++)
        {
        sum1=0;
        if(maxb1[x])
        {
            for(y=0;y<w;y++)
            {
                if(maxb2[y])
                    sum1+=a[x][y];
            }
            if(sum1<0){
                maxb1[x]=0;
                maxrcount--;
            }
        }
        }
            }
        }
    }
    printf("%d %d\n",maxrcount,maxccount);
    for(i=0;i<h;i++)
    {
        if(maxb1[i])
            printf("%d ",i);
    }
    printf("\n");
    for(i=0;i<w;i++)
    {
        if(maxb2[i])
            printf("%d ",i);
    }

    return 0;
}

