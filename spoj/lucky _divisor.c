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

int arr[101];
int main()
{
    int t,n,num,max=0,maxdiv,i;
    t=scan();
    while(t--)
    {
        n=scan();
        max=0;
        while(n--)
        {
            num=scan();
            arr[num]++;
        }
        for(i=100;i>=1;i--)
        {
            if(arr[i]>0 && arr[i]%i==0)
            {
                if(arr[i]>max)
                {
                    max=arr[i];
                    maxdiv=i;
                }
                if(arr[i]==max)
                {
                    maxdiv=i;
                }
            }
        }
        if(max>0)
        {
            printf("%d\n",maxdiv);
        }
        else
        {
            printf("-1\n");
        }
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
