#include<stdio.h>
#include<stdbool.h>
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

int arr[100][100];
bool mem[100][100];
int main()
{
    int t,n,m,i,j,count;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&arr[i][j]);
                mem[i][j]=0;
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]!=-1 && mem[i][j]!=1){
                if(i+1<n && arr[i][j]==arr[i+1][j])
                {
                    if(mem[i+1][j]!=1) count++;

                    mem[i][j]=1;
                    mem[i][j+1]=1;

                }
                if(j+1<m && arr[i][j]==arr[i][j+1])
                {
                    if(mem[i][j+1]!=1 && mem[i][j]!=1) count++;

                    mem[i][j]=1;
                    mem[i][j+1]=1;

                }
                if(j-1>=0 && arr[i][j]==arr[i][j-1])
                {
                    if(mem[i][j-1]!=1 && mem[i][j]!=1) count++;

                    mem[i][j]=1;
                    mem[i][j-1]=1;

                }
                if(i-1>=0 && arr[i][j]==arr[i-1][j])
                {
                    if(mem[i-1][j]!=1 && mem[i][j]!=1) count++;

                    mem[i][j]=1;
                    mem[i-1][j]=1;

                }
                if(j-1>=0 && i-1>0 && arr[i][j]==arr[i-1][j-1])
                {
                    if(mem[i-1][j-1]!=1 && mem[i][j]!=1) count++;

                    mem[i][j]=1;
                    mem[i-1][j-1]=1;

                }
                if(i-1>=0 && j+1<m && arr[i][j]==arr[i-1][j+1])
                {
                    if(mem[i-1][j+1]!=1 && mem[i][j]!=1) count++;

                    mem[i][j]=1;
                    mem[i-1][j+1]=1;

                }
                if(j-1>=0 && i+1<n && arr[i][j]==arr[i+1][j-1])
                {
                    if(mem[i+1][j-1]!=1 && mem[i][j]!=1) count++;

                    mem[i][j]=1;
                    mem[i+1][j-1]=1;

                }
                if(i+1<n && j+1<m && arr[i][j]==arr[i+1][j+1])
                {
                    if(mem[i][j]!=1 && mem[i+1][j+1]!=1) count++;

                    mem[i][j]=1;
                    mem[i+1][j+1]=1;

                }}
                //printf("%d %d %d\n",i,j,count);
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
