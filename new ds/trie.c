#include<stdio.h>
#include<stdbool.h>
#include<string.h>
typedef struct node
{
    bool word;
    int prefixes;
    struct node* child[26];
}node;
node *root=NULL;
void init()
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

void addword(node* root,char *word)
{
    node* t,*prev;
    t=root;prev=root;
    int l=strlen(word),i,index;
    for(i=0;i<l;i++)
    {
        t->prefixes++;
        index=(int)word[i]-97;
        prev=t;
        t=t->child[index];
        if(t==NULL)
        {
            addnode(prev,word[i]);
            t=prev->child[index];
        }
        if(i==l-1)
            t->word=true;

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
int main()
{
    init();
    //char word[]="garvit";
    //int l=strlen(word);
    addword(root,"garvit");
    printf("%d",find(root,"garvit"));
}
