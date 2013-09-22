#include<stdio.h>
#include<stdbool.h>
bool arr[60][60];
bool mine[60][60];
int left;
void eval(int x,int y,int n)
{
    arr[x][y]=1;
    char c,c1;
    int num;
    //printf("ok\n");
    scanf("%c",&c);
    getchar();
    //printf("%c\n",c);
    if(c=='M')
    {
        printf("N %d %d\n",x,y);
        fflush(stdout);
        mine[x][y]=1;
        left--;
    }
    else
    {
        num=c-'0';
        if(x>0)
        {
            if(y>0)
            {
                if(mine[x-1][y-1]) num--;
            }
            if(mine[x-1][y]) num--;
            if(y<n-1)
            {
                if(mine[x-1][y+1]) num--;
            }
        }
        if(y>0)
        {
            if(mine[x][y-1]) num--;
        }
        if(y<n-1)
        {
            if(arr[x][y+1])
            {
                if(mine[x][y+1]) num--;
            }
            else
            {
                arr[x][y+1]=1;

                if(num!=0){
                printf("S %d %d\n",x,y+1);
                fflush(stdout);
                scanf("%c",&c1);
                getchar();

                if(c1=='M')
                {
                    mine[x][y+1]=1;
                    num--;
                    printf("N %d %d\n",x,y+1);
                    left--;

                }

                }
            }
        }
        if(x<n-1)
        {
            if(y>0)
            {
                if(arr[x+1][y-1])
                {
                if(mine[x+1][y-1]) num--;
                }
                else
                {
                arr[x+1][y-1]=1;

                if(num!=0){
                printf("S %d %d\n",x+1,y-1);
                fflush(stdout);
                scanf("%c",&c1);
                getchar();

                if(c1=='M')
                {
                    mine[x+1][y-1]=1;
                    num--;
                    printf("N %d %d\n",x+1,y-1);
                    left--;
                }

                }
                }
            }
                if(arr[x+1][y])
                {
                if(mine[x+1][y]) num--;
                }
                else
                {
                arr[x+1][y]=1;

                if(num!=0){
                printf("S %d %d\n",x+1,y);
                fflush(stdout);
                scanf("%c",&c1);
                getchar();

                if(c1=='M')
                {
                    mine[x+1][y]=1;
                    num--;
                    printf("N %d %d\n",x+1,y);
                    left--;
                }

                }
                }

             if(y<n-1)
             {
                if(arr[x+1][y+1])
                {
                if(mine[x+1][y+1]) num--;
                }
                else
                {
                arr[x+1][y+1]=1;
                //printf("ok");
                if(num==1)
                {
                    mine[x+1][y+1]=1;
                    num--;
                    printf("N %d %d\n",x+1,y+1);
                    fflush(stdout);
                    left--;
                }
                else{

                mine[x+1][y+1]=0;
                }
                }
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
