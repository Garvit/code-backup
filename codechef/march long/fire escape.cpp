#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<set>
#define MOD 1000000007
#define getchar getchar_unlocked
using namespace std;

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
    bool head,isnew;
    struct node *next;
    int count,index;
}node;

//node (*emp)[100000];
set<int> heads;
int main()
{
    int t,m,n,i,j,num=0;
    long long ans=1;
    set<int>::iterator it;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        ans=1;
        node **emp=(node**)calloc(n+1,sizeof(node*));
        for(i=1;i<=n;i++)
        {
            emp[i]=(node*)calloc(1,sizeof(node));
            //cout<<emp[i];
            emp[i]->head=false;
            //cout<<emp[i]->head<<endl;
            emp[i]->isnew=true;
            emp[i]->index=i;
            emp[i]->count=0;
            emp[i]->next=0;
        }

        num=n;
        while(m--)
        {
            i=scan();
            j=scan();
            //printf("ok");
            if(emp[i]->isnew && emp[j]->isnew)
            {
                //printf("ok");
                emp[i]->isnew=false;
                emp[j]->isnew=false;
                emp[i]->head=true;
                emp[i]->count=2;
                heads.insert(i);
                emp[j]->next=emp[i];
                emp[i]->next=emp[i];
                num-=2;
            }
            else if(emp[i]->isnew && !emp[j]->isnew)
            {
                emp[i]->isnew=false;
                node *t=emp[j]->next;
                while(t->head==false)
                {
                    t=t->next;
                }
                emp[i]->next=t;
                t->count++;
                num--;
            }
            else if(!emp[i]->isnew && emp[j]->isnew)
            {
                emp[j]->isnew=false;
                node *t=emp[i]->next;
                while(t->head==false)
                {
                    t=t->next;
                }
                emp[j]->next=t;
                t->count++;
                num--;
            }
            else
            {
                //printf("4");
                node *t=emp[i]->next;
                while(t->head==false)
                {
                    t=t->next;
                }
                node *t1=emp[j]->next;
                while(t1->head==false)
                {
                    t1=t1->next;
                }
                if(t1!=t){
                t1->head=false;
                heads.erase(t1->index);
                t1->next=t;
                t->count+=t1->count;}
            }

        }
        printf("%d ",heads.size()+num);
        for(it=heads.begin();it!=heads.end();it++)
        {
            ans=(ans*emp[*it]->count)%MOD;
        }
        printf("%lld\n",ans);
        heads.clear();
    }
    return 0;
}
