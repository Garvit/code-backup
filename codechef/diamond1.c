#include<stdio.h>
double coeff[2000][2000]={0};
double prev[2000][2000]={0};
double now[2000][2000]={0};

void poss(int n)
{
    int i,j;
    now[0][0]=0.5;
    now[0][n-1]=0.5;
    for(i=1;i<n;i++)
    {
        now[i][0]=0.5*prev[i-1][0];
        for(j=1;j<n-1;j++)
        {
            now[i][j]=0.5*prev[i-1][j]+0.5*prev[i-1][j-1];
        }
        now[i][n-1]=0.5*prev[i-1][n-2];
    }

    for(i=0;i<n;i=i+1)
    {
        for(j=0;j<n;j=j+2)
            {
                coeff[n-1][i]+=now[j][i];
            }

    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            prev[i][j]=now[i][j];
            now[i][j]=0;
        }
    }

}
int main()
{
    int i,j;
    coeff[1][0]=0.5;
    coeff[1][1]=0.5;
    prev[0][0]=0.5;
    prev[0][1]=0.5;
    prev[1][0]=0.5;
    prev[1][1]=0.5;
    for(i=3;i<=2000;i++)
    {
        poss(i);
        printf("done %d\n",i);
    }
    printf("ok done");
    FILE *fp;
    fp=fopen("diamond.txt","w");
    fprintf(fp,"{");
    for(i=0;i<2000;i++)
    {
        fprintf(fp,"{");
        for(j=0;j<2000;j++)
        {
            if(coeff[i][j]==0)
                break;
            fprintf(fp,"%.4f,",coeff[i][j]);

        }

        fprintf(fp,"},");
    }
    fprintf(fp,"}");
}

