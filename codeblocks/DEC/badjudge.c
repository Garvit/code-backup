#include<stdio.h>

double dp[100][100];
int s[100][100];
//int k[100][100];
int inline scan()
{
    int N = 0,f=0;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-')
    {
        f=1;
        C=getchar();
    }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return f?(-N):N;
}
int main()
{
    int t,n,i,j;
    double temp1,temp2;
    t=scan();
    while(t--)
    {
        n=scan();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                s[i][j]=scan();
            }
        }
        dp[0][0]=0;
        //k[0][0]=0;
        for(i=1;i<n;i++)
        {
            dp[0][i]=(dp[0][i-1]+s[0][i]);
            dp[i][0]=(dp[i-1][0]+s[i][0]);
            //k[0][i]=k[0][i-1]+1;
            //k[i][0]=k[i-1][0]+1;
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                temp1=(dp[i-1][j]+s[i][j]);
                temp2=(dp[i][j-1]+s[i][j]);
                if(temp1>temp2)
                {
                    dp[i][j]=temp1;
                    //k[i][j]=k[i-1][j]+1;
                }
                else
                {
                    dp[i][j]=temp2;
                    //k[i][j]=k[i][j-1]+1;
                }
            }
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%f ",dp[i][j]);
            }
            printf("\n");
        }*/
        dp[n-1][n-1]=(dp[n-1][n-2]>dp[n-2][n-1])?dp[n-1][n-2]:dp[n-2][n-1];

        if(dp[n-1][n-1]<0)
        {
            printf("Bad Judges\n");
        }
        else
        {
            printf("%f\n",dp[n-1][n-1]/(2*n-3));
        }
        memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));
        //memset(k,0,sizeof(k));
    }
    return 0;
}
