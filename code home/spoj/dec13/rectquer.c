#include<stdio.h>
#include<stdbool.h>

int arr[300][300][11];
int main()
{
    int n,q,i,j,num,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&num);
            if(i==0 && j==0)
                arr[0][0][num]=1;
            else if(i==0)
            {
                arr[i][j][num]=1;
                for(k=1;k<=10;k++)
                    arr[i][j][k]+=arr[i][j-1][k];
            }
            else if(j==0)
            {
                arr[i][j][num]=1;
                for(k=1;k<=10;k++)
                    arr[i][j][k]+=arr[i-1][j][k];
            }
            else
            {
                arr[i][j][num]=1;
                for(k=1;k<=10;k++)
                    arr[i][j][k]+=arr[i-1][j][k]+arr[i][j-1][k]-arr[i-1][j-1][k];
            }


        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=1;k<=10;k++) printf("%d ",arr[i][j][k]);
            printf("\n");
        }
    }*/
        scanf("%d",&q);
        int x1,x2,y1,y2,ans;
        for(i=0;i<q;i++)
        {
            ans=0;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1--;x2--;y1--;y2--;
            if(x1==0 && y1==0)
            {
                for(j=1;j<=10;j++)
                {
                    if(arr[x2][y2][j]>0) ans++;
                }
            }
            else if(x1==0)
            {
                for(j=1;j<=10;j++)
                {
                    if(arr[x2][y2][j]-arr[x2][y1-1][j]>0) ans++;
                }
            }
            else if(y1==0)
            {
                for(j=1;j<=10;j++)
                {
                    if(arr[x2][y2][j]-arr[x1-1][y2][j]>0) ans++;
                }
            }
            else
            {
                for(j=1;j<=10;j++)
                {
                    if(arr[x2][y2][j]-arr[x1-1][y2][j]-arr[x2][y1-1][j]+arr[x1-1][y1-1][j]>0) ans++;
                }
            }
            printf("%d\n",ans);

        }

    return 0;
}
