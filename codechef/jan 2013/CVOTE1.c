#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef 
struct trienode
{
    struct trienode *arr[52], *country, *parent;
    int count1, count2, isChef, isCountry;
    char parc, str[20];
} trienode;

void copy(char *a, char *b)
{
    int i=0;
    while(b[i]!='\0')
    {
        a[i]=b[i];
        i++;
    }
    a[i]='\0';
    return;
}

int getIndex(int c)
{
    if(c>='a'&&c<='z')
        return c-'a';
    else
        return c-'A'+26;
}

int length(char *a)
{
    int i=0;
    while(a[i]!='\0') i++;
    return i;
}

int cmpstr(char *a, char *b)
{
    int alen = length(a), blen = length(b), min = MIN(alen,blen),i=0;
    for(i=0; i<min; i++)
    {
        if(a[i]==b[i])
            continue;
        if(a[i]<b[i])
            return 1;
        if(a[i]>b[i])
            return -1;
    }
    if(alen<blen)
        return 1;
    else if(alen>blen)
        return -1;
    else
        return 0;
}

trienode* make_trienode()
{
    int i=0;
    trienode *ret = (trienode*) malloc(sizeof(trienode));
    ret->count1=0;
    ret->count2=0;
    ret->isChef=0;
    ret->isCountry=0;
    (ret->str)[0]='\0';
    ret->parc='\0';
    ret->country=NULL;
    ret->parent=NULL;
    for(i=0;i<52;i++)
        ret->arr[i]=NULL;
    return ret;
}

void setPair(char *chef, char *country, trienode *root, trienode* chefs[], int *chef_count, trienode* countries[], int *country_count)
{
    int i,c,k;
    trienode *it1, *it2;

    i=0,c=0,k=0;
    it1 = root;
    while((c=chef[i++])!='\0')
    {
        k = getIndex(c);
        if(it1->arr[k]==NULL)
            it1->arr[k] = make_trienode();
        it1->arr[k]->parent = it1;
        it1->arr[k]->parc = c;
        it1 = it1->arr[k];
    }
    it1->isChef=1;
    copy(it1->str,chef);
    chefs[(*chef_count)++]=it1;

    i=0,c=0,k=0;
    it2 = root;
    while((c=country[i++])!='\0')
    {
        k = getIndex(c);
        if(it2->arr[k]==NULL)
            it2->arr[k] = make_trienode();
        it2->arr[k]->parent = it2;
        it2->arr[k]->parc = c;
        it2 = it2->arr[k];
    }
    if(it2->isCountry==0)
    {
        it2->isCountry=1;
        copy(it2->str,country);
        countries[(*country_count)++]=it2;
    }

    it1->country = it2;
    return;
}

trienode* countChefs(char *chef, trienode *root)
{
    int i,c;
    trienode *it1;
    i=0,c=0;
    it1 = root;
    while((c=chef[i++])!='\0')
    {
        c = getIndex(c);
        if(it1->arr[c]==NULL)
            it1->arr[c] = make_trienode();
        it1 = it1->arr[c];
    }
    it1->count1 += 1;
    it1->country->count2 += 1;
}

/*
void make_string_util(char *a, int *n, int *i, trienode* node)
{
    if(node->parent==NULL) // means 'root' node.
        return;
    *n += 1;
    make_string_util(a,n,i,node->parent);
    a[(*i)++] = node->parc;
    *n -= 1;
    if(*n==0)
    {
        a[*i]='\0';
    }
    return;
}

char* make_string(trienode* node)
{
    char *ret = (char*) malloc(20*sizeof(char));
    int len_count=0, iter=0;
    make_string_util( ret, &len_count, &iter, node);
    return ret;
}
*/

trienode* chooseMax(trienode *a, trienode *b, int type)  
{
    if(type==1)
    {
        if(a->count1 > b->count1)
            return a;
        else if(a->count1 < b->count1)
            return b;
        else
        {
            int temp = cmpstr( a->str, b->str);
            if(temp==1)
                return a;
            else if(temp==-1)
                return b;
        }
    }
    else
    {
        if(a->count2 > b->count2)
            return a;
        else if(a->count2 < b->count2)
            return b;
        else
        {
            int temp = cmpstr( a->str, b->str);
            if(temp==1)
                return a;
            else if(temp==-1)
                return b;
        }
    }
}

void printstr(char *a, char c)
{
    int i=0;
    while(a[i]!='\0')
    {
        putchar(a[i]);
        i++;
    }
    putchar(c);
    return;
}

int main()
{
    int N=0,M=0,i=0;
    char chef[20], country[20];
    scanf("%d %d", &N, &M);

    trienode  *chefs[N], *countries[N], *root=make_trienode();
    int chef_count=0, country_count=0;

    // setting chef-country pairs.
    for(i=0; i<N; i++)
    {
        scanf("%s %s", chef, country);
        setPair(chef, country, root, chefs, &chef_count, countries, &country_count);
    }

    // counting chefs' votes.
    for(i=0; i<M; i++)
    {
        scanf("%s", chef);
        countChefs(chef, root);
    }

    // determining highest voted chef.
    trienode *max_chef = chefs[0];
    for(i=1; i<chef_count; i++)
    {
        max_chef = chooseMax( max_chef, chefs[i], 1);
    }

    // determining highest voted country.
    trienode *max_country = countries[0];
    for(i=1; i<country_count; i++)
    {
        max_country = chooseMax( max_country, countries[i], 2);
    }

    printstr(max_country->str,'\n'); 
    printstr(max_chef->str,'\n');
    return 0;
}
