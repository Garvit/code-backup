#include<stdio.h>
#include<stdbool.h>
int a[300][300];
bool b1[300];
bool b2[300];
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
    int h,w,i,j,k,rcount=0,ccount=0,total,f;
    long long sum=0;
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
