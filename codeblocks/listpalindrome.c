#include<stdio.h>
#include<stdbool.h>
typedef struct node
{
    int value;
    struct node* next;
}node;

node* reverse(node* head)
{
    node* prev=NULL;
    node* curr=head;
    node* nex=curr->next;
    while(nex!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=nex;
        nex=nex->next;
    }
    curr->next=prev;
    return curr;

}
node* getmiddle(node* head)
{
    node* half=head;
    node* full=head;
    while(full!=NULL && full->next!=NULL)
    {
        full=full->next->next;
        half=half->next;
    }
    return half;
}

bool checkpalin(node* head)
{
    node* middle=getmiddle(head);

    middle=reverse(middle);
    while(head!=NULL)
    {
        if(middle->value!=head->value)
          return false;

        middle=middle->next;
        head=head->next;
    }
    return true;

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
}
