#include<stdio.h>
#define ull unsigned long long int
ull a[50][50];
ull dpbob[50][50][50][50];
ull row[50][50][50];
ull column[50][50][50];
ull ac;
ull bob(int r1,int r2,int c1,int c2);
long long int inline scan()
{
    long long int N = 0;
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

int inline scan1()
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
ull alice(int r1,int r2,int c1,int c2)
{
    if(r2<r1 || c2<c1)
    {
        return 0;
    }


    ull fr=0,lr=0,fc=0,lc=0,min;
    int i,choice;

    if(row[r1][c1][c2]!=0)
        fr=row[r1][c1][c2];
    else
    {
        for(i=c1;i<=c2;i++)
        {
            fr+=a[r1][i];
        }
        row[r1][c1][c2]=fr;
    }

    if(row[r2][c1][c2]!=0)
        lr=row[r2][c1][c2];
    else{
    for(i=c1;i<=c2;i++)
    {
        lr+=a[r2][i];
    }
    row[r2][c1][c2]=lr;
    }

    if(column[c1][r1][r2]!=0)
        fc=column[c1][r1][r2];
    else {
    for(i=r1;i<=r2;i++)
    {
        fc+=a[i][c1];
    }
    column[c1][r1][r2]=fc;
    }

    if(column[c2][r1][r2]!=0)
        lc=column[c2][r1][r2];
    else {
    for(i=r1;i<=r2;i++)
    {
        lc+=a[i][c2];
    }
    column[c2][r1][r2]=lc;
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
            return bob(r1+1,r2,c1,c2);
            break;
        case 2:
            return bob(r1,r2-1,c1,c2);
            break;
        case 3:
            return bob(r1,r2,c1+1,c2);
            break;
        case 4:
            return bob(r1,r2,c1,c2-1);
            break;

    }
}

ull bob(int r1,int r2,int c1,int c2)
{
    if(r2<r1 || c2<c1)
    {
       return 0;
    }
    if(r1==r2)
    {
        ull sum=0;
        int i;
        for(i=c1;i<=c2;i++)
        {
            sum+=a[r1][i];
        }
        return sum;
    }

    if(c1==c2)
    {
        ull sum=0;
        int i;
        for(i=r1;i<=r2;i++)
        {
            sum+=a[i][c1];
        }
        return sum;
    }
    if(dpbob[r1][r2][c1][c2]!=0)
        return dpbob[r1][r2][c1][c2];

    ull fr=0,lr=0,fc=0,lc=0,max,temp1;
    ull sum[4],temp[4];
    int i;

    if(row[r1][c1][c2]!=0)
        fr=row[r1][c1][c2];
    else
    {
        for(i=c1;i<=c2;i++)
        {
            fr+=a[r1][i];
        }
        row[r1][c1][c2]=fr;
    }

    if(row[r2][c1][c2]!=0)
        lr=row[r2][c1][c2];
    else{
    for(i=c1;i<=c2;i++)
    {
        lr+=a[r2][i];
    }
    row[r2][c1][c2]=lr;
    }

    if(column[c1][r1][r2]!=0)
        fc=column[c1][r1][r2];
    else {
    for(i=r1;i<=r2;i++)
    {
        fc+=a[i][c1];
    }
    column[c1][r1][r2]=fc;
    }

    if(column[c2][r1][r2]!=0)
        lc=column[c2][r1][r2];
    else {
    for(i=r1;i<=r2;i++)
    {
        lc+=a[i][c2];
    }
    column[c2][r1][r2]=lc;
    }

    temp1=ac;
    sum[0]=fr+alice(r1+1,r2,c1,c2);
    temp[0]=ac;
    ac=temp1;
    sum[1]=lr+alice(r1,r2-1,c1,c2);
    temp[1]=ac;
    ac=temp1;
    sum[2]=fc+alice(r1,r2,c1+1,c2);
    temp[2]=ac;
    ac=temp1;
    sum[3]=lc+alice(r1,r2,c1,c2-1);
    temp[3]=ac;
    max=sum[0];
    ac=temp[0];
    for(i=1;i<4;i++)
    {
        if(sum[i]>max)
        {
            max=sum[i];
            ac=temp[i];
        }
    }
    dpbob[r1][r2][c1][c2]=max;
    return max;

}
int main()
{
    int t,i,j,n,m,k,l;
    ull ans;
    t=scan1();
    while(t--)
    {
        ac=0;

        n=scan1();
        m=scan1();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<m;k++)
                {
                    for(l=0;l<m;l++)
                    {
                        dpbob[i][j][k][l]=0;

                    }
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                for(k=0;k<m;k++)
                {
                    row[i][j][k]=0;
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    column[i][j][k]=0;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                a[i][j]=scan();
            }
        }

        ans=alice(0,n-1,0,m-1);
        //printf("ans: %llu ",ans);
        //printf("ac: %llu\n",ac);
        if(ac==ans)
        {
            printf("%llu\n",ans+ac);
        }
        else
        {
            printf("%llu\n",(ans>ac?ans:ac));
        }

    }

    return 0;
}

