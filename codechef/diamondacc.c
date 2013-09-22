#include<stdio.h>

double coeff[2010][2010];
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
int main()
{
    int t,i,j,n,v;
    double ans;
    coeff[0][0]=1;
    for(i=1;i<2000;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0)
            {
                coeff[i][j]=1-coeff[i-1][j]/2;
            }
            else if(j==i)
            {
                coeff[i][j]=1-coeff[i-1][j-1]/2;
            }
            else
            {
                coeff[i][j]=1-(coeff[i-1][j]+coeff[i-1][j-1])/2;
            }
        }
    }
    t=scan();
    for(i=0;i<t;i++)
    {
        n=scan();
        ans=0;
        for(j=0;j<n;j++)
        {
            v=scan();
            ans=ans+v*coeff[n-1][j];
        }
        printf("%lf\n",ans);
    }
    return 0;
}
