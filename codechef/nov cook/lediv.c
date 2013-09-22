#include<stdio.h>
int a[100000];
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

int lcd(int a,int b)
{
    int m=a>b?b:a;
    int i,flag=0;
    for(i=2;i<=m;i++)
    {
        if(a%i==0 || b%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int t,n,i,j,ans,flag;
    t=scan();
    while(t--)
    {
        ans=-1;
        n=scan();


        for(i=0;i<n;i++)
        {
            a[i]=scan();
            if(a[i]==1)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            printf("-1\n");
            continue;
        }
        if(n==1)
        {
            for(i=2;i<=a[0];i++)
            {
                if(a[0]%i==0)
                {
                    break;
                }
            }
            printf("%d\n",i);
            continue;
        }
        ans=lcd(a[0],a[1]);
        for(i=1;i<n;i++)
        {
            ans=lcd(ans,a[i]);
            if()
        }

        printf("%d\n",ans);
    }
    return 0;
}
