#include<stdio.h>
#include<stdbool.h>
#include<math.h>
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
int a[1000];
int b[1000];
int arr[1000001];
int main()
{
    int t,n1,n2,i,flag,min,j;
    t=scan();
    while(t--)
    {
        flag=0;
        n1=scan();
        for(i=0;i<n1;i++)
        {
            a[i]=scan();
            arr[a[i]]=1;
        }
        n2=scan();
        for(i=0;i<n2;i++)
        {
            b[i]=scan();
            if(arr[b[i]]) flag=1;
        }
        if(flag==1)
        {
            printf("0\n");
        }
        else
        {
            min=abs(a[0]-b[0]);
            for(i=0;i<n1;i++)
            {
                for(j=0;j<n2;j++)
                {
                    int t=abs(a[i]-b[j]);
                    if(t<min) min=t;

                    if(min==1)
                    {
                        printf("1\n");
                        break;
                    }
                }
                if(j!=n2) break;
            }
            if(i==n1) printf("%d\n",min);
        }
        memset(arr,0,sizeof(arr));
    }
}
