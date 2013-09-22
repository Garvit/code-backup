#include<stdio.h>
#include<string.h>

typedef struct node
{
    int size,memory;
    int *data;
}node;

node* newnode(int mem)
{
    node* res;
    res->memory=mem;
    res->data=(int*)malloc(mem*sizeof(int));
    return res;
}
void nodedelete(node *t)
{
    free(t->data);
}

void init(node* t,int size)
{
    int i;
    t->size=size;
    for(i=0;i<size;i++)
    {
        t->data[i]=0;
    }
}

void add(node* t,int k,int add)
{
    while(k<t->size)
    {
        t->data[k]+=add;
        k|=k+1;
    }
}

int get(node* t,int k)
{
    int res=0;
    while(k>=0)
    {
        res+=t->data[k];
        k=(k&(k+1))-1;
    }
    return res;
}
int range(node* t,int a,int b)
{
    return get(t,b)-get(t,a-1);
}
/*
int get(node* t,int k)
{
    int sum=0;
    while(k>0)
    {
        sum+=t->data[k];
        k-=(k & -k);
    }
    return sum;

}

void add(node* t,int k,int val)
{
    while(k<=t->size)
    {
        t->data[k]+=val;
        k+=(k & -k);
    }
}
*/
int main()
{
    node* ft=(newnode(10));
    init(ft,10);
    add(ft,0,10);
    add(ft,1,10);
    add(ft,3,5);
    int a=get(ft,2);
    printf("%d",a);
    return 0;
}
