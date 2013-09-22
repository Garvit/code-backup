#include<stdio.h>
#define MAX(a,b) a>b?a:b;
int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1;C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}
int arr[50000];
typedef struct node
{
    struct node *left,*right,*parent;
    int value,flag,lower,higher;
}node;


node* eval(int a,int b)
{
    node *temp=malloc(sizeof(node));

    temp->lower=a;
    temp->higher=b;
    temp->flag=0;
    if(a==b)
    {
        temp->value=arr[a];
        temp->flag=1;
    }
    else{
    temp->left=eval(a,(a+b)/2);
    temp->right=eval((a+b)/2+1,b);}
    return temp;
}
void help(node* root)
{
    if(root->flag==1) return;

    help(root->left);
    help(root->right);
    root->value=MAX(root->left->value,root->right->value);

}

int max(int a,int b,node *t)
{
    if(t->lower==a && t->higher==b) return t->value;

    int mid=(t->lower+t->higher)/2;
    if(b<=mid) return max(a,b,t->left);
    else
    {
        if(a>mid) return max(a,b,t->right);
        else
        {
            return MAX(max(a,mid,t->left),max(mid+1,b,t->right));
        }
    }
}
int main()
{
    int n,m,i,a,b;
    n=scan();
    for(i=0;i<n;i++)
    {
        arr[i]=scan();
    }
    node *root=eval(0,n-1);
    help(root);
    /*m=scan();
    while(m--)
    {
        a=scan();
        b=scan();
        printf("%d\n",max(a-1,b-1,root));
    }*/
    return 0;
}
