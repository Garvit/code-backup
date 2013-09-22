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
    int n,x1,x2,x3,y1,y2,y3,a,b,c;
    int ans=0;
    n=scan();
    while(n--)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        a=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
        b=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
        c=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        if(a+b==c || a+c==b || b+c==a)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
