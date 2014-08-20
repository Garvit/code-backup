#include<stdio.h>

int req[1000][1000];
int curr[1000][1000];
short int steps[1000000][5];
int main()
{
    int n,i,j,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&req[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(curr[i][j]!=req[i][j])
            {
                int c=req[i][j],u=i+1,d=i+1,l=j+1,r=j+1,k1,k2;
                //printf("%d\n",c);

                //printf("%d %d %d %d\n",u,d,l,r);

                for(k1=j+1;k1<n;k1++)
                {
                    if(req[i][k1]!=c)
                        break;
                }
                r=k1;
                //printf("%d %d %d %d\n",u,d,l,r);

                for(k1=i+1;k1<n;k1++)
                {
                    for(k2=l-1;k2<r;k2++)
                    {
                        if(req[k1][k2]!=c)
                            break;
                    }
                    if(k2!=r) break;
                    d=k1+1;
                }
                //printf("%d %d %d %d\n",u,d,l,r);
                for(k1=u-1;k1<d;k1++)
                {
                    for(k2=l-1;k2<r;k2++)
                    {
                        curr[k1][k2]=c;
                    }
                }
                //printf("ok");
                steps[ans][0]=c;
                steps[ans][1]=u;
                steps[ans][2]=d;
                steps[ans][3]=l;
                steps[ans][4]=r;
                ans++;
                //printf("ok");
            }
        }
    }
    printf("%d\n",ans);
    for(i=0;i<ans;i++)
    {
        printf("%d %d %d %d %d\n",steps[i][0],steps[i][1],steps[i][2],steps[i][3],steps[i][4]);
    }
    return 0;
}
