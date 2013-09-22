#include<stdio.h>
#define ull unsigned long long int
ull a[50][50];

ull ac,bc;
void bob(int r1,int r2,int c1,int c2);
void alice(int r1,int r2,int c1,int c2)
{
    if(r2<r1 || c2<c1)
    {
        return 0;
    }


    ull fr=0,lr=0,fc=0,lc=0,min;
    int i,choice;
    for(i=c1;i<=c2;i++)
    {
        fr+=a[r1][i];
    }

    for(i=c1;i<=c2;i++)
    {
        lr+=a[r2][i];
    }

    for(i=r1;i<=r2;i++)
    {
        fc+=a[i][c1];
    }
    for(i=r1;i<=r2;i++)
    {
        lc+=a[i][c2];
    }

    min=fr;
    choice=1;
    if(lr<min)
    {
        min=lr;
        choice=2;
    }

    if(fc<min)
    {
        min=fc;
        choice=3;
    }

    if(lc<min)
    {
        min=lc;
        choice=4;
    }
    ac+=min;
    switch(choice)
    {
        case 1:
            bob(r1+1,r2,c1,c2);
            break;
        case 2:
            bob(r1,r2-1,c1,c2);
            break;
        case 3:
            bob(r1,r2,c1+1,c2);
            break;
        case 4:
            bob(r1,r2,c1,c2-1);
            break;

    }
}

void bob(int r1,int r2,int c1,int c2)
{
    if(r2<r1 || c2<c1)
    {
        return 0;
    }


    ull fr=0,lr=0,fc=0,lc=0,max;
    int i,choice;
    for(i=c1;i<=c2;i++)
    {
        fr+=a[r1][i];
    }

    for(i=c1;i<=c2;i++)
    {
        lr+=a[r2][i];
    }

    for(i=r1;i<=r2;i++)
    {
        fc+=a[i][c1];
    }
    for(i=r1;i<=r2;i++)
    {
        lc+=a[i][c2];
    }

    max=fr;
    choice=1;
    if(lr>max)
    {
        max=lr;
        choice=2;
    }

    if(fc>max)
    {
        max=fc;
        choice=3;
    }

    if(lc>max)
    {
        max=lc;
        choice=4;
    }
    bc+=max;
    switch(choice)
    {
        case 1:
            alice(r1+1,r2,c1,c2);
            break;
        case 2:
            alice(r1,r2-1,c1,c2);
            break;
        case 3:
            alice(r1,r2,c1+1,c2);
            break;
        case 4:
            alice(r1,r2,c1,c2-1);
            break;

    }

}
int main()
{
    int t,i,j,n,m,k,l;
    ull ans;
    scanf("%d",&t);
    while(t--)
    {
        ac=0;bc=0;

        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%llu",&a[i][j]);
            }
        }
        alice(0,n-1,0,m-1);
        //printf("ans: %llu ",ans);
        //printf("ac: %llu\n",ac);
        if(ac==bc)
        {
            printf("%llu\n",bc+ac);
        }
        else
        {
            printf("%llu\n",(bc>ac?bc:ac));
        }

    }
    //printf("%d",t);
    return 0;
}


