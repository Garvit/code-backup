#include<stdio.h>
#include<stdbool.h>
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
bool pr[1001];
void sieve()
{
    int start=3,i;

    while(1)
    {
        for(i=3*start;i<1000;i+=(2*start))
        {
            pr[i]=1;
            //printf("%d ",i);
        }
        start+=2;
        for(i=start;i<1000;i+=2)
        {
            if(pr[i]==0)
            {
                break;
            }
        }
        if(i>=1000)
            break;
        start=i;
    }
}
int arr[1001][1001];
void eval(int n)
{
    int i,j,num,count;

    for(i=2;i<=n;i++)
    {
        num=i,count=0;

        while(num>0)
        {
            count+=num/2;
            num=num/2;
        }
        //printf("%d\n",count);
        arr[i][2]=count;
        for(j=3;j<=i;j+=2)
        {
            if(pr[j]==0)
            {
                num=i;count=0;
                while(num>0)
                {
                    count+=num/j;
                    num=num/j;
                }
            arr[i][j]=count;
        }
    }
    }
}
int ans[1000];
int main()
{
    int n,flag=0,i,j,k,k1,,flag1;
    n=scan();
    sieve();
    if(n%2==1 && pr[n]==0) printf("No solution");
    else
    {
        eval(n);
        //printf("%d",arr[n][2]);
        k=0;
        i=(n%2==1)?n-2:n-1;
        for(;i>=2;i--)
        {
            printf("%d %d\n",i,arr[n][i]);

            int min=arr[n][2]/arr[i][2],t;

            if(min!=0)
            {
                for(j=3;j<=i;j+=2)
                {
                    flag=0;
                    if(pr[j]==0)
                    {
                        t=arr[n][j]/arr[i][j];
                        if(t==0){ flag=1; break; }
                        else
                        {
                            if(t<min) min=t;
                        }
                    }
                }
                if(flag==0)
                {
                    ans[i]=min;
                    k+=min;
                    arr[n][2]-=arr[i][2]*min;
                    for(j=3;j<=i;j+=2)
                    {
                        arr[n][j]-=arr[i][j]*min;
                    }
                }
            }
        }


        if(k!=0)
        {
            printf("%d! = ",n);
            k1=0;
            for(i=2;i<n;i++)
            {
                while(ans[i]--)
                {
                    if(k1==0)
                        printf("%d!",i);
                    else
                        printf(" * %d!",i);

                    k1=1;
                }
            }
        }
        else
            printf("No solution");

    }



    return 0;
}

