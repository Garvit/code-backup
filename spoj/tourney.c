#include<stdio.h>
#include<limits.h>

#define getchar getchar_unlocked
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
int arr[1<<20];
int tree[1<<21];

inline int max2(int a,int b)
{
    int r=(arr[a]>arr[b])?a:b;
    //printf("%d %d %d\n",arr[a],arr[b],r);
    return r;
}

void build(int n,int l,int r)
{
    if(l>r) return;
    else if(l==r)
    {
        tree[n]=l;
        return;
    }

    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    tree[n]=max2(tree[2*n],tree[2*n+1]);

}

int main()
{
    int n,m,i,s,count,j;
    char c;
    n=scan();
    m=scan();
    for(i=0;i<(1<<n);i++)
    {
        arr[i]=scan();
    }
    build(1,0,(1<<n)-1);
    /*for(j=0;j<(1<<(n+1));j++)
    {
        printf("%d ",tree[j]);
    }
    printf("\n");*/
    while(m--)
    {
        c=getchar();
        //printf("%c",c);
        if(c=='R')
        {
            i=scan();
            s=scan();
            int p=(1<<(n))+i-1;
            arr[i-1]=s;
            p=p/2;
            while(p!=0)
            {
                tree[p]=max2(tree[2*p],tree[2*p+1]);
                p=p/2;
            }

        }
        else if(c=='W')
        {
            getchar();
            printf("%d\n",tree[1]+1);
        }
        else if(c=='S')
        {
            count=0;
            i=scan();
            int p=(1<<(n))+i-1;
            p=p/2;
            while(p!=0)
            {
                if(tree[p]==i-1)
                    count++;
                 else
                    break;

                p=p/2;
            }
            printf("%d\n",count);
        }

    }
    return 0;
}

