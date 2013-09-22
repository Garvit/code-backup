#include<stdio.h>
#include<stdbool.h>
typedef struct node
{
    int value;
    struct node* next;
}node;

void copyn(node *n1,node *n2)
{
    n2->value=n1->value;
    n2->next=n1->next;

}

node* reverse(node *head)
{
    node *prev=NULL;
    node *curr=calloc(1,sizeof(node));
    copyn(head,curr);
    node *nex=(curr->next);
    while(nex!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=calloc(1,sizeof(node));
        copyn(nex,curr);
        nex=nex->next;
    }
    curr->next=prev;
    return curr;

}


bool checkpalin(node *head)
{
    //node nhead=reverse(head);
    node* nhead=reverse(head);
    display(nhead);


    while(head!=NULL)
    {
        if(nhead->value!=head->value)
          return false;

        nhead=(nhead->next);
        head=(head->next);
    }
    return true;

}
void display(node* head)
{
    while(head!=NULL)
    {
            printf("%d",head->value);
            head=head->next;
    }
}
main()
{
    node* head=malloc(sizeof(node));
    head->value=1;
    node* a=malloc(sizeof(node));
    a->value=2;
    head->next=a;
    node* b=malloc(sizeof(node));
    b->value=3;
    a->next=b;
    node* c=malloc(sizeof(node));
    c->value=2;
    b->next=c;
    node* d=malloc(sizeof(node));
    d->value=1;
    c->next=d;
    d->next=NULL;
    printf("%d",checkpalin(head));
    display(head);
}
