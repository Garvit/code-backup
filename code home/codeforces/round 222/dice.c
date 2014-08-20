#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,fp=0,draw=0,sp=0;
    scanf("%d %d",&a,&b);
    int diff=abs(a-b);
    if(a==b)
    {
        draw=6;
    }
    else
    {
        if(diff%2==0) draw=1;
        if(a<b)
        {
            fp=a;sp=6-b+1;
        }
        else{
            sp=b;fp=6-a+1;}

        fp+=(diff-1)/2;
        sp+=(diff-1)/2;
    }
    printf("%d %d %d",fp,draw,sp);
    return 0;
}
