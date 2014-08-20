#include<stdio.h>
#include<stdbool.h>

char arr[20][20];
short int demon[400][2];
short int lava[20][20];
int r,c;
bool check(int i,int j)
{
    if(i<0 || j<0 || i>=r || j>=c) return 0;

    return arr[i][j]=='^';
}

bool cpc(int i,int j)
{
    if(!(check(i,j-1) && check(i,j-2))) return false;
    if(!(check(i-1,j) && check(i-2,j))) return false;
    if(!(check(i,j+1) && check(i,j+2))) return false;
    if(!(check(i+1,j) && check(i+2,j))) return false;

    return true;

}
void printlava()
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",lava[i][j]);
        printf("\n");
    }
    printf("\n");
}
void swap(int i,int j)
{
    int t=demon[i][0];
    demon[i][0]=demon[j][0];
    demon[j][0]=t;

    t=demon[i][1];
    demon[i][1]=demon[j][1];
    demon[j][1]=t;
}
void spread(int i,int j,int p)
{
    //printf("spread called %d %d\n",i,j);
    int k=i;
    while(k>=0 && lava[k][j]==0)
    {
        lava[k][j]=p;
        k--;
    }
    k=j+1;
    while(k<c && lava[i][k]==0)
    {
        lava[i][k]=p;
        k++;
    }
    k=i+1;
    while(k<r && lava[k][j]==0)
    {
        lava[k][j]=p;
        k++;
    }
    k=j-1;
    while(k>=0 && lava[i][k]==0)
    {
        lava[i][k]=p;
        k--;
    }

}
void retract(int i,int j,int p)
{
    int k=i;
    while(k>=0 && lava[k][j]==p)
    {
        lava[k][j]=0;
        k--;
    }
    k=j+1;
    while(k<c && lava[i][k]==p)
    {
        lava[i][k]=0;
        k++;
    }
    k=i+1;
    while(k<r && lava[k][j]==p)
    {
        lava[k][j]=0;
        k++;
    }
    k=j-1;
    while(k>=0 && lava[i][k]==p)
    {
        lava[i][k]=0;
        k--;
    }
}

bool play(int i,int n)
{
    //printf("play called %d\n",i);
    //printlava();
    int j;
    bool flag=0;
    for(j=i;j<n;j++)
    {
        int x=demon[j][0];
        int y=demon[j][1];
        if(lava[x][y]==0)
        {
            swap(i,j);
            spread(x,y,i+1);
            if(play(i+1,n)==false) flag=1;
            retract(x,y,i+1);
            swap(i,j);
            if(flag==1) return true;
        }
    }
    return false;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        int k=0;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%s",arr[i]);
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j]!='#' && cpc(i,j))
                {
                    demon[k][0]=i;
                    demon[k][1]=j;
                    k++;
                }
            }
        }
        bool ans=play(0,k);
        //printlava();
        if(ans)
            printf("Asuna\n");
        else
            printf("Kirito\n");
    }
    return 0;
}

