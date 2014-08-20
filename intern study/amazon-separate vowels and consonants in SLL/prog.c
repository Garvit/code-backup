#include<stdio.h>
#include<string.h>
typedef struct node
{
    char c;
    struct node* next;
}node;

node* head;
void func()
{
    node* headv=NULL;
    node* headc=NULL;
    node* currv=NULL;
    node* currc=NULL;
    node* t=head;
    while(t!=NULL)
    {
        node* p=t->next;
        if(t->c=='A' || t->c=='E' || t->c=='I' || t->c=='O' || t->c=='U')
        {
            if(currv==NULL)
            {
                headv=t;
            }
            else
                currv->next=t;
            currv=t;
            t->next=headc;
        }
        else
        {
            if(currc==NULL)
            {
                headc=t;
            }
            else
                currc->next=t;
            currc=t;
            t->next=NULL;
        }
        t=p;
    }
    currv->next=headc;
    head=headv;
}
void create()
{
    char str[]="AMAZON";
    int i;
    head=malloc(sizeof(node));
    head->c=str[0];
    node *prev=head;
    for(i=1;i<strlen(str);i++)
    {
        node* t=malloc(sizeof(node));
        t->c=str[i];
        t->next=NULL;
        prev->next=t;
        prev=t;
    }
}
void print()
{
    node* t=head;
    while(t!=NULL)
    {
        printf("%c",t->c);
        t=t->next;
    }
    printf("\n");
}
int main()
{
    create();
    print();
    func();
    print();
}
