#include<stdio.h>
#include<string.h>
int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar_unlocked();
    while ((C < '0' || C>'9') && C != '-') C=getchar_unlocked();
    if(C=='-'){ sign=-1; C=getchar_unlocked();}
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N*sign;
}
typedef struct node
{
    int num,count;
    char name[20];
    struct node* next;
    struct node* prev;
}node;
node *head,*tail;

int main()
{
    int n,i,k=0,left,j;
    char str[20];
    n=scan();

    for(i=0;i<n;i++)
    {
        left=scan();
        if(left == -1)
        {
            printf("%d %s\n",tail->count,tail->name);
            tail=tail->prev;
            k--;
        }
        else
        {
            scanf("%s",str);
            if(left==0)
                continue;
            //printf("%s",str);
            if(k==0)
            {
                node *n=malloc(sizeof(node));
                n->count=0;
                strcpy(n->name,str);
                n->num=left;
                n->next=NULL;
                n->prev=NULL;
                head=n;
                tail=n;
                k++;
            }
            else
            {
                if(left > tail->num)
                {
                    tail->count++;
                }
                else
                {
                    node *n=malloc(sizeof(node));
                    n->count=0;
                    strcpy(n->name,str);
                    n->num=left;
                    n->next=NULL;
                    n->prev=tail;
                    tail->next=n;
                    tail=n;
                    k++;
                }
            }
        }
    }
    return 0;
}
