#include<stdio.h>
#include<stdbool.h>
#include<string.h>
typedef struct node
{
    bool word;
    int prefixes;
    struct node* child[26];
    char* string;
}node;
node *root;

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
void init(node* root)
{
    root=malloc(sizeof(node));
    int i;
    for(i=0;i<26;i++)
    {
        root->child[i]=NULL;
    }
    root->word=false;
    root->prefixes=0;
}

void addnode(node* n,char c)
{
    printf("enter");
    node* t=malloc(sizeof(node));
    int i,index=(int)c-97;
    for(i=0;i<26;i++)
    {
        t->child[i]=NULL;
    }
    t->word=false;
    t->prefixes=0;
    n->child[index]=t;
}

bool find(node* root,char *word)
{
    node* t;
    t=root;
    int l=strlen(word),i,index;
    for(i=0;i<l;i++)
    {
        index=(int)word[i]-97;
        t=t->child[index];

        if(t==NULL)
            return false;
    }
    return t->word;
}

void addword(node* root,char* word)
{
    node* t,*prev;
    t=root;prev=root;
    printf("ok");
    int l=strlen(word),i,index;
    for(i=0;i<l;i++)
    {
        printf("ok");
        t->prefixes=(t->prefixes)+1;
        printf("ok");
        index=(int)word[i]-97;
        prev=t;
        t=t->child[index];
        printf("ok");
        if(t==NULL)
        {
            addnode(prev,word[i]);
        }
        if(i==l-1){
            t->word=true;
            t->string=word;
        }

    }
}
void printwords(node* root)
{
    if(root==NULL)
        return;
    if(root->word)
    {
        printf("%s\n",root->string);
    }
    int i;
    for(i=0;i<26;i++)
    {
        printwords(root->child[i]);
    }
}
int countprefixes(node *root,char* prefix)
{
    node* t;
    t=root;
    int l=strlen(prefix),i,index;
    for(i=0;i<l;i++)
    {
        index=(int)prefix[i]-97;
        t=t->child[index];

        if(t==NULL)
            return -1;
    }
    return t->prefixes;
}
void printprefixes(node* root,char* prefix)
{
    node* t;
    t=root;
    int l=strlen(prefix),i,index;
    for(i=0;i<l;i++)
    {
        index=(int)prefix[i]-97;
        t=t->child[index];

        if(t==NULL)
        {
            printf("No match.\n");
            return;
        }

    }
    if(t->prefixes==0)
    {
         printf("No match.\n");
            return;
    }
    else
    {
        printwords(t);
    }
}
int main()
{
    int n,k,z;
    char str[30];
    init(root);
    n=scan();
    while(n--)
    {
        scanf("%s",str);
        addword(root,str);
    }
    k=scan();
    for(z=1;z<=k;z++)
    {
        scanf("%s",str);
        printf("Case #%d:\n",z);
        printprefixes(root,str);
    }
}
