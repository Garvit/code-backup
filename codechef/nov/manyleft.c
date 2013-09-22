#include<stdio.h>

int board[40][40];
typedef struct move
{
    int x1,x2,y1,y2;
    struct move* next;

}move;

move* head;
move* tail;
int main()
{
    int n,i,j,num=0,k=0,flag,x1,x2,y1,y2;
    char c[40];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",c);
        for(j=0;j<n;j++)
        {
            if(c[j]=='*')
                board[i][j]=1;
            else if(c[j]=='.')
                board[i][j]=0;
        }
    }
    while(1)
    {
        flag=0;
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              if(board[i][j]==1)
              {

                  if(i>1 && board[i-1][j]==1 && board[i-2][j]==0)
                  {
                      board[i][j]=0;
                      board[i-1][j]=0;
                      board[i-2][j]=1;
                      x1=j;
                      y1=i;
                      x2=j;
                      y2=i-2;
                      num++;


                  }
                  else if(j<n-2 && board[i][j+1]==1 && board[i][j+2]==0)
                  {
                      board[i][j]=0;
                      board[i][j+1]=0;
                      board[i][j+2]=1;
                      x1=j;
                      y1=i;
                      x2=j+2;
                      y2=i;
                      num++;


                  }
                  else if(j>1 && board[i][j-1]==1 && board[i][j-2]==0)
                  {
                      board[i][j]=0;
                      board[i][j-1]=0;
                      board[i][j-2]=1;
                      x1=j;
                      y1=i;
                      x2=j-2;
                      y2=i;
                      num++;


                  }
                  else if(i<n-2 && board[i+1][j]==1 && board[i+2][j]==0)
                  {
                      board[i][j]=0;
                      board[i+1][j]=0;
                      board[i+2][j]=1;
                      x1=j;
                      y1=i;
                      x2=j;
                      y2=i+2;

                      num++;


                  }



                  else
                  {
                      continue;
                  }
                  move* temp=malloc(sizeof(move));
                  temp->x1=x1;
                  temp->y1=y1;
                  temp->x2=x2;
                  temp->y2=y2;
                  temp->next=NULL;
                  if(head==NULL)
                  {
                      head=tail=temp;
                  }
                  else
                  {
                      tail->next=temp;
                      tail=tail->next;
                  }
                  break;
              }
          }
          if(j!=n)
          {
              flag=1;
              break;
          }
      }
      if(flag==0)
            break;
    }
    printf("%d\n",num);
    if(num>0)
    {
        move* temp=head;
        while(temp!=NULL)
        {
            printf("%d %d %d %d\n",temp->x1,temp->y1,temp->x2,temp->y2);
            temp=temp->next;
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}
