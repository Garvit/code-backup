#include<stdio.h>
#include<algorithm>

using namespace std;
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
    int t,n;
    t=scan();
    while(t--)
    {
        n=scan();
        long long total=0;
        int num3=0,num1=0;
        int *a=new int[n];
        int *b=new int[n];
        for(int i=0;i<n;i++)
            a[i]=scan();
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            b[i]=scan();
        }

        sort(b,b+n);
        int k=0,i=0;
        while(k<n && b[k]==1)
        {
            num1++;
            k++;
        }
        while(k<n && b[k]==2) k++;
        while(k<n && b[k]==3)
        {
            num3++;
            k++;
        }

        for(i=0;i<n;i++)
        {
            if(a[i]>1)
            {
                if(a[i]==2)
                {
                    while(k<n && b[k]<=4)
                        k++;
                    total+=n-k+num1;
                }
                else if(a[i]==3)
                    total+=n-num3;
                else
                {
                    while(k<n && b[k]<=a[i])
                        k++;
                    total+=n-k+num1;
                }
            }

        }
        double ans=(double)total/n;
        printf("%lf\n",ans);

    }
    return 0;
}
