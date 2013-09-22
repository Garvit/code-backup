#include<stdio.h>
#include<string.h>
#define getchar getchar_unlocked
int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}

typedef struct node
{
    int size;
    int *data;
}node;

node newnode(int size)
{
    node res;
    res.data=(int*)malloc(size*sizeof(int));
    res.size=size;
    int i;
    for(i=0;i<size;i++)
    {
        res.data[i]=0;
    }
    return res;
}


void add(node* t,int k,int add)
{
    while(k<t->size)
    {
        t->data[k]+=add;
        k+=(k & -k);
    }
}

int get(node* t,int k)
{
    int res=0;
    while(k>0)
    {
        res+=t->data[k];
        k-=(k & -k);
    }
    return res;
}
int range(node* t,int a,int b)
{
    return get(t,b)-get(t,a-1);
}
int rowtime[510000],coltime[510000],rowto[510000],colto[510000];

int main()
{
    int n,q,i,j,k,r,c,x,ans;
    char str[20];
    node row[2],col[2];
    n=scan();
    q=scan();
    row[0]=newnode(q+10);
    row[1]=newnode(q+10);
    col[0]=newnode(q+10);
    col[1]=newnode(q+10);

    for(i=1;i<=q;i++)
    {
        scanf("%s",str);
        if(!(strcmp(str,"RowSet")))
        {
            r=scan();
            x=scan();
            if(rowtime[r]) add(&row[rowto[r]],rowtime[r],-1);

            add(&row[x],i,1);
            rowtime[r]=i;
            rowto[r]=x;
        }
        else if(!(strcmp(str,"RowQuery")))
        {
            r=scan();
            if(rowto[r]==0)
                ans=n-range(&col[1],rowtime[r],i);
            else
                ans=range(&col[0],rowtime[r],i);

            printf("%d\n",ans);
        }
        else if(!(strcmp(str,"ColSet")))
        {
            c=scan();
            x=scan();
            if(coltime[c]) add(&col[colto[c]],coltime[c],-1);

            add(&col[x],i,1);
            coltime[c]=i;
            colto[c]=x;
        }
        else if(!(strcmp(str,"ColQuery")))
        {
            c=scan();
            if(colto[c]==0)
                ans=n-range(&row[1],coltime[c],i);
            else
                ans=range(&row[0],coltime[c],i);

            printf("%d\n",ans);
        }
    }
    return 0;
}
