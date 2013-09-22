#include<stdio.h>
#include<stdbool.h>

char arr[500][500];
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
int main()
{
    int t,i,ans=0,j;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%s",arr[i]);
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j]!='#' && cpc(i,j)) ans++;
            }
        }
        printf("%d\n",ans);
    }
}
