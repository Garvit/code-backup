#include<stdio.h>
#include<string.h>

int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}

double prob[41];
double cost[41];
int total[41][2];
int main()
{
    int t,n,c,p,m,i,k;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        for(i=0;i<n;i++)
        {
            c=scan();
            p=scan();
            total[c][0]++;
            total[c][1]+=p;
        }
        prob[0]=1;
        for(i=1;i<41;i++)
        {
            if(total[i][0]!=0)
            {
                int j=0;
                double np=1.0;
                for(k=1;k<=total[i][0];k++)
                    np/=2;
                for(;j<41;j++)
                {
                    if(prob[j]==0) break;
                }
                int temp=j;
                for(;j>0;j--)
                {
                    prob[j]=prob[j]*np+prob[j-1]*(1-np);
                    cost[j]=cost[j]*np+(cost[j-1]*(1-np)+prob[j-1]*0.5*total[i][1]);
                }
                prob[0]=prob[0]*np;
            }

        }
        double num=0,den=0;
        for(i=m;i<41;i++)
        {
            if(prob[i]==0) break;
            num+=cost[i];
            den+=prob[i];
        }
        double ans=num/den;
        printf("%.9lf\n",ans);
        memset(prob,0,sizeof(prob));
        memset(cost,0,sizeof(cost));
        memset(total,0,sizeof(total));
    }
    return 0;
}

