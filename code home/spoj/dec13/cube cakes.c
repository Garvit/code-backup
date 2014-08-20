#include<stdio.h>
#include<string.h>
int arr[40][40][40];
int main()
{
    int t,n,i,j,k,p;
    scanf("%d",&t);
    char c1[64010],c2[64010];
    while(t--)
    {
        scanf("%d %d",&n,&p);
        scanf("%s",c1);
        scanf("%s",c2);
        //printf("%s\n",c1);
        //printf("%s\n",c2);
        int z=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(i==0 && j==0 && k==0)
                    {
                        ;
                    }
                    else if(i==0 && j==0)
                    {
                        arr[i][j][k]=arr[i][j][k-1];
                    }
                    else if(i==0 && k==0)
                    {
                        arr[i][j][k]=arr[i][j-1][k];
                    }
                    else if(k==0 && j==0)
                    {
                        arr[i][j][k]=arr[i-1][j][k];
                    }
                    else if(i==0)
                    {
                        arr[i][j][k]=arr[i][j][k-1]+arr[i][j-1][k]-arr[i][j-1][k-1];
                    }
                    else if(j==0)
                    {
                        arr[i][j][k]=arr[i][j][k-1]+arr[i-1][j][k]-arr[i-1][j][k-1];
                    }
                    else if(k==0)
                    {
                        arr[i][j][k]=arr[i-1][j][k]+arr[i][j-1][k]-arr[i-1][j-1][k];
                    }
                    else
                    {
                        arr[i][j][k]=arr[i-1][j][k]+arr[i][j-1][k]+arr[i][j][k-1]-arr[i-1][j-1][k]-arr[i-1][j][k-1]-arr[i][j-1][k-1]+arr[i-1][j-1][k-1];
                    }

                    if(c1[z]==c2[z])
                        arr[i][j][k]++;
                    z++;
                }
            }
        }
        int size,count=0,flag=0,cp;
        for(size=n;size>0;size--)
        {
            for(i=0;i<=n-size;i++)
            {
                for(j=0;j<=n-size;j++)
                {
                    for(k=0;k<=n-size;k++)
                    {
                        if(i==0 && j==0 && k==0)
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1];
                        }
                        else if(i==0 && j==0)
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1]-arr[i+size-1][j+size-1][k-1];
                        }
                        else if(i==0 && k==0)
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1]-arr[i+size-1][j-1][k+size-1];
                        }
                        else if(k==0 && j==0)
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1]-arr[i-1][j+size-1][k+size-1];
                        }
                        else if(i==0)
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1]-arr[i+size-1][j+size-1][k-1]-arr[i+size-1][j-1][k+size-1]+arr[i+size-1][j-1][k-1];
                        }
                        else if(j==0)
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1]-arr[i+size-1][j+size-1][k-1]-arr[i-1][j+size-1][k+size-1]+arr[i-1][j+size-1][k-1];
                        }
                        else if(k==0)
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1]-arr[i-1][j+size-1][k+size-1]-arr[i+size-1][j-1][k+size-1]+arr[i-1][j-1][k+size-1];
                        }
                        else
                        {
                            cp=arr[i+size-1][j+size-1][k+size-1]-arr[i-1][j+size-1][k+size-1]-arr[i+size-1][j-1][k+size-1]-arr[i+size-1][j+size-1][k-1]+arr[i-1][j-1][k+size-1]+arr[i-1][j+size-1][k-1]+arr[i+size-1][j-1][k-1]-arr[i-1][j-1][k-1];
                        }
                        cp=cp*100/(size*size*size);
                        if(cp>=p)
                        {
                            flag=size;
                            count++;
                        }
                    }
                }
            }
            if(flag!=0) break;
        }
        if(flag==0)
            printf("-1\n");
        else
            printf("%d %d\n",flag,count);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
