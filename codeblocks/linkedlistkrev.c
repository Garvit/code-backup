#include<stdio.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

void insert(node *root,int p)
{
    while(root->next!=NULL)
    {
        root=root->next;
    }
    node *temp=calloc(1,sizeof(struct node));
    root->next=temp;
    temp->value=p;
    temp->next=NULL;

}
int find(node* root,int p)
{
    while(root!=NULL && root->value!=p)
    {
        root=root->next;
    }
    if(root==NULL)
     return 0;
    else
     return 1;
}

void delete(node* root,int p)
{
    while(root!=NULL && (root->next)->value!=p)
    {
        root=root->next;
    }
    if(root==NULL)
        {
            printf("Not found");
            return;
        }
     node* temp=root->next;
     root->next=temp->next;
     free(temp);
}

void print(node* root)
{
    while(root!=NULL)
    {
        printf("%d ",root->value);
        root=root->next;
    }
    printf("\n");
}
int count(node* root)
{
    int c=0;
    while(root!=NULL)
    {
        c++;
        root=root->next;

    }
    return c;
}
node* reverse(node* root,int k)
{
    int c=count(root);
    //printf("%d\n",c);
    if(c>k){
    int f=1,n=1,t=(int)c/k;
    //printf("%d\n",t);
    node* nex, *prev, *current, *temp, *temp1;
    temp=root;
    current=root;
    prev=NULL;
    nex=root->next;
    while(f<k && nex!=NULL)
    {
        current->next=prev;
        f++;
        prev=current;
        current=nex;
        nex=nex->next;
    }
    current->next=prev;
    root=current;
    temp->next=nex;
    while(n<t){
    if(nex==NULL)
        break;
     f=1;
     current=nex;
     temp1=current;
     nex=nex->next;
     prev=NULL;
    while(f<k && nex!=NULL)
    {
        current->next=prev;
        f++;
        prev=current;
        current=nex;
        nex=nex->next;
    }
    current->next=prev;
    temp->next=current;
    temp1->next=nex;
    temp=temp1;
    n++;
    }
    }
    return root;
}
main()
{
    struct node* head;
    head=malloc(sizeof(struct node));
    head->value=1;
    head->next=NULL;

    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    print(head);
    head=reverse(head,5);
    print(head);
    //printf("%d",head->value);
}


