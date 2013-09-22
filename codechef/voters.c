#include<stdio.h>

typedef struct node
{
    int count;
    int value;
    struct node* next;
}node;
node *head;
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N;
}
int main()
{
    int n1,n2,n3,n,flag,num=0;
    node *temp;
    n1=scan();
    n2=scan();
    n3=scan();
    n=scan();

    head=malloc(sizeof(node));
    head->value=n;
    head->count=1;
    head->next=0;
    n1--;
    temp=head;
    while(n1--)
    {
        n=scan();
        flag=0;
        node* t=malloc(sizeof(node));
        t->value=n;
        t->count=1;
        t->next=0;
        temp->next=t;
        temp=t;

    }
    n=scan();

    if(n< head->value)
    {
        node* t=malloc(sizeof(node));
        t->value=n;
        t->count=1;
        t->next=head;
        head=t;
        temp=head;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->value==n)
            {
                if(temp->count==1)
                    num++;
                temp->count++;
                flag=1;

                break;
            }
            else if(temp->value<n && n<temp->next->value)
            {
                node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=temp->next;
                temp->next=t;
                flag=1;
                temp=t;
                break;
            }
            temp=temp->next;
        }
        if(flag==0){
        if(temp->value==n)
        {
            if(temp->count==1)
                    num++;
            temp->count++;
        }
        else
        {
            node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=NULL;;
                temp->next=t;
                temp=t;
        }
        }
    }
    n2--;
    while(n2--)
    {
        n=scan();
        flag=0;

        while(temp->next!=NULL)
        {
            if(temp->value==n)
            {
                if(temp->count==1)
                    num++;
                temp->count++;
                flag=1;

                break;
            }
            else if(temp->value<n && n<temp->next->value)
            {
                node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=temp->next;
                temp->next=t;
                flag=1;
                temp=t;
                break;
            }
            temp=temp->next;
        }
        if(flag==0){
        if(temp->value==n)
        {
            if(temp->count==1)
                    num++;
            temp->count++;
        }
        else
        {
            node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=NULL;;
                temp->next=t;
                temp=t;
        }
        }
    }
    n=scan();

    if(n< head->value)
    {
        node* t=malloc(sizeof(node));
        t->value=n;
        t->count=1;
        t->next=head;
        head=t;
        temp=head;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->value==n)
            {
                if(temp->count==1)
                    num++;
                temp->count++;
                flag=1;

                break;
            }
            else if(temp->value<n && n<temp->next->value)
            {
                node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=temp->next;
                temp->next=t;
                flag=1;
                temp=t;
                break;
            }
            temp=temp->next;
        }
        if(flag==0){
        if(temp->value==n)
        {
            if(temp->count==1)
                    num++;
            temp->count++;
        }
        else
        {
            node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=NULL;;
                temp->next=t;
                temp=t;
        }
        }
    }
    n3--;
    while(n3--)
    {
        n=scan();
        flag=0;

        while(temp->next!=NULL)
        {
            if(temp->value==n)
            {
                if(temp->count==1)
                    num++;
                temp->count++;
                flag=1;

                break;
            }
            else if(temp->value<n && n<temp->next->value)
            {
                node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=temp->next;
                temp->next=t;
                flag=1;
                temp=t;
                break;
            }
            temp=temp->next;
        }
        if(flag==0){
        if(temp->value==n)
        {
            if(temp->count==1)
                    num++;
            temp->count++;
        }
        else
        {
            node* t=malloc(sizeof(node));
                t->value=n;
                t->count=1;
                t->next=NULL;;
                temp->next=t;
                temp=t;
        }
        }
    }
    temp=head;
    printf("%d\n",num);
    while(temp!=NULL)
    {
        //printf("%d %d\n",temp->value,temp->count);
        if(temp->count>1)
        {
            printf("%d\n",temp->value);
        }
        temp=temp->next;
    }
    return 0;
}
