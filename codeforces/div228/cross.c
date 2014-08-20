#include<stdio.h>

char board[110][110];


int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&board[i]);
    }
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<n-1;j++)
        {
            if(board[i][j]=='#' && board[i-1][j]=='#' && board[i+1][j]=='#' && board[i][j-1]=='#' && board[i][j+1]=='#')
            {
                board[i][j]='.';
                board[i-1][j]='.';
                board[i+1][j]='.';
                board[i][j-1]='.';
                board[i][j+1]='.';
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(board[i][j]=='#')
            {
                printf("NO\n");
                break;
            }
        }
        if(j!=n) break;
    }
    if(i==n) printf("YES\n");
    return 0;
}
