#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char str[50][55];
bool check[50][50];
typedef struct node
{
    int x1,x2,y1,y2;
    char c;
    struct node* next;
}node;

node *head1,*head2,*tail1,*tail2;
int main()
{
    int n,i,count=0,j,k1,k2,z,x,black=0,white=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str[i]);

    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(str[i][j]=='B' && check[i][j]==0)
            {
                k1=j;k2=i;z=i;
                while(str[i][j]=='B' && j<n)
                {
                    check[i][j]=1;
                    j++;
                }

                for(z=i+1;z<n;z++)
                {
                    for(x=k1;x<j;x++)
                    {
                        if(str[z][x]!='B')
                            break;
                    }
                    if(x!=j) break;
                    for(x=k1;x<j;x++) check[z][x]=1;
                }


                black++;
                node *temp=malloc(sizeof(node));
                temp->x1=i;
                temp->y1=k1;
                temp->x2=z-1;
                temp->y2=j-1;
                temp->c='B';
                temp->next=NULL;
                if(!head1)
                {
                    head1=temp;
                    tail1=temp;
                }
                else
                {
                    tail1->next=temp;
                    tail1=temp;
                }

            }
        }

    }
    memset(check,0,sizeof(check));
        white++;
                node *temp=malloc(sizeof(node));
                temp->x1=0;
                temp->y1=0;
                temp->x2=n-1;
                temp->y2=n-1;
                temp->c='B';
                temp->next=NULL;
                head2=temp;
                tail2=temp;
       for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
        {
            if(str[i][j]=='W' && check[i][j]==0)
            {
                k1=j;k2=i;z=i;
                while(str[i][j]=='W' && j<n)
                {
                    check[i][j]=1;
                    j++;
                }

                for(z=i+1;z<n;z++)
                {
                    for(x=k1;x<j;x++)
                    {
                        if(str[z][x]!='W')
                            break;
                    }
                    if(x!=j) break;
                    for(x=k1;x<j;x++) check[z][x]=1;
                }


                white++;
                node *temp=malloc(sizeof(node));
                temp->x1=i;
                temp->y1=k1;
                temp->x2=z-1;
                temp->y2=j-1;
                temp->c='W';
                temp->next=NULL;

                    tail2->next=temp;
                    tail2=temp;


            }
        }

        }

    node *t;
    if(black<=white)
    {
        t=head1;
        count=black;
    }
    else
    {
        t=head2;
        count=white;
    }
    printf("%d\n",count);

        while(t)
        {
            printf("%d %d %d %d %c\n",t->x1,t->y1,t->x2,t->y2,t->c);
            t=t->next;
        }

    return 0;
}
