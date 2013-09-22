#include<stdio.h>
#include<stdbool.h>
bool arr[60][60];
bool mine[60][60];
int left;
void eval(int x,int y,int n)
{
    arr[x][y]=1;
    char c;
    int num;
    scanf("%c",&c);
    getchar();
    if(c=='M')
    {
        printf("N %d %d\n",x,y);
        fflush(stdout);
        mine[x][y]=1;
        left--;
    }
    else if(c=='0')
    {
        if(y<n-1) arr[x][y+1]=1;
        if(x<n-1)
        {
            if(y>0) arr[x+1][y-1]=1;
            arr[x+1][y]=1;
            if(y<n-1) arr[x+1][y+1]=1;
        }
    }
    else
    {
        num=c-'0';
        //printf("num : %d",num);
        if(x>0)
        {
            if(y>0)
            {
                if(arr[x-1][y-1] && mine[x-1][y-1]) num--;
            }
            if(arr[x-1][y] && mine[x-1][y]) num--;
            if(y<n-1)
            {
                if(arr[x-1][y+1] && mine[x-1][y+1]) num--;
            }
        }
        if(y>0)
        {
            if(arr[x][y-1] && mine[x][y-1]) num--;
        }
        if(num==0)
        {
            if(y<n-1) arr[x][y+1]=1;
            if(x<n-1)
            {
                if(y>0) arr[x+1][y-1]=1;
                arr[x+1][y]=1;
                if(y<n-1) arr[x+1][y+1]=1;
            }
        }
    }
}
int main()
{
    int n,m,k,i,j;
    scanf("%d %d%d",&n,&m,&k);
    getchar();
    left=m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {

            if(!arr[i][j] && left!=0)
            {
                printf("S %d %d\n",i,j);
                fflush(stdout);
                eval(i,j,n);
                //printf("ok");
            }

        }
    }
    printf("Done");
    fflush(stdout);
    return 0;
}
