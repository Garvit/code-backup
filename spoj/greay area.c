#include<stdio.h>

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
int width[20];
int main()
{
    int n,w,i,v;
    double max,last,ans;

    while(1)
    {
        n=scan();
        w=scan();
        ans=0.01;
        max=0;
        if(n==0 && w==0) break;

        for(i=0;i<n;i++)
        {
            v=scan();
            width[v/w]++;
            if(width[v/w]>max)
            {
                max=width[v/w];
            }
        }
        last=0;
        for(i=20;i>=0;i--)
        {
            if(width[i]!=0)
            {
                last=i;
                break;
            }
        }

        for(i=0;i<=last;i++)
        {
            //printf("%d\n",width[i]);
            ans+=(width[i]/max * (last-i)/last);
        }
        printf("%.6f\n",ans);
        memset(width,0,sizeof(width));
    }
    return 0;
}
