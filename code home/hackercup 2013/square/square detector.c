#include<stdio.h>

char inp[30][30];
int main()
{
    int t,n,mini,maxi,minj,maxj,i,j,z;
    scanf("%d",&t);
    for(z=1;z<=t;z++)
    {
        scanf("%d",&n);
        mini=-1;
        getchar();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                inp[i][j]=getchar();
                if(inp[i][j]=='#')
                {
                    if(mini==-1)
                    {
                        mini=maxi=i;
                        minj=maxj=j;
                    }
                    else
                    {
                        if(i>maxi) maxi=i;
                        if(j<minj) minj=j;
                        if(j>maxj) maxj=j;
                    }
                }
            }

            getchar();
        }
        //printf("%d %d %d %d\n",mini,maxi,minj,maxj);
        int flag=0;
        if((maxi-mini)==(maxj-minj)){
        for(i=mini;i<=maxi;i++)
        {
            for(j=minj;j<=maxj;j++)
            {
                if(inp[i][j]!='#')
                {
                    flag=1; break;
                }
            }
            if(flag==1) break;
        }
        }
        else flag=1;

        printf("Case #%d: ",z);
        if(flag==1) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
