#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool select[500];
int main()
{
    int t,n,m,i,s,j;
    int arr[500];
    double err;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            select[i]=0;
        }
        select[0]=1;
        select[n-1]=1;
        err=0;
        s=2;
        double max=-1,val,diff,er;
        int si,prev,next;
        if(m>2)
        {
            diff=((double)arr[n-1]-arr[0])/(n-1);
            for(i=1;i<n;i++)
            {
                val=arr[0]+i*diff;
                er=val>arr[i]?(val-arr[i]):(arr[i]-val);
                //printf("%.4lf\n",er);
                if(er>max)
                {
                    max=er;
                    si=i;
                }
            }
            select[si]=1;s++;
            //printf("%d %d\n",si,s);
            prev=0;
            for(;s<m;s++)
            {
                max=-1;
                for(i=1;i<n;i++)
                {
                    if(select[i]==1)
                    {
                        next=i;
                        diff=((double)arr[next]-arr[prev])/(next-prev);
                        for(j=prev+1;j<next;j++)
                        {
                            val=arr[prev]+diff*(j-prev);
                            er=val>arr[j]?(val-arr[j]):(arr[j]-val);
                            if(er>max)
                            {
                                max=er;
                                si=j;
                            }
                        }
                        prev=next;
                    }
                }
                select[si]=1;

            //printf("%d\n",si);
            }
        }
            err=0;
            prev=0;
            for(i=1;i<n;i++)
                {
                    if(select[i]==1)
                    {
                        //printf("next: %d\n",i);
                        next=i;
                        diff=((double)arr[next]-arr[prev])/(next-prev);
                        for(j=prev+1;j<next;j++)
                        {
                            val=arr[prev]+diff*(j-prev);
                            err+=(val>arr[j]?(val-arr[j]):(arr[j]-val));
                            //printf("%.4lf\n",err);
                        }
                        prev=next;
                    }
                }
          printf("%.4lf\n",err/n);
    }
    return 0;
}
