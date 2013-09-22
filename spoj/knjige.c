#include<stdio.h>

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

int main()
{
    int n,ans=0,i;
    n=scan();
    int *arr=calloc(n,sizeof(int));
    int *pos=calloc(n+1,sizeof(int));
    for(i=0;i<n;i++)
    {
        arr[i]=scan();
        pos[arr[i]]=i;
    }
    for(i=n;i>1;i--)
    {
        if(pos[i]<pos[i-1])
        {
            ans=i-1;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}
