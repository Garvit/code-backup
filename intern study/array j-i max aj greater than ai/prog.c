#include<stdio.h>
#include<limits.h>
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int run_min[100],run_max[100];
int main()
{
    int arr[]={5,6,3,4,7};
    int i,j;
    run_min[0]=arr[0];
    run_max[4]=arr[4];
    //printf("%d %d\n",run_max[4],run_min[0]);
    for(i=1;i<5;i++)
    {
        run_min[i]=min(run_min[i-1],arr[i]);
    }
    for(i=3;i>=0;i--)
    {
        run_max[i]=max(run_max[i+1],arr[i]);
    }
    int maxdiff=0,maxi=0,maxj=0;
    for(i=0,j=0;i<5 && j<5;)
    {
        if(run_max[j]>run_min[i])
        {
            if(maxdiff<(j-i))
            {
                maxdiff=j-i;
                maxi=i;
                maxj=j;

            }
            j++;

        }
        else
        {
            i++;
        }
    }
    printf("%d %d %d",maxi,maxj,maxdiff);
}
