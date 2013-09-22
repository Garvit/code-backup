#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int diff;
int guess(int l,int r,int s);
main()
{
    diff=-1;
    int n,s;
    scanf("%d",&n);

    printf("pick a number\n");
    scanf("%d",&s);
    int g=guess(1,n,s);
    printf("Number of guess:- %d",g+1);

}

int guess(int l,int r,int s)
{
    if(l==r && l==s)
        return 1;
    if(diff==-1)
    {
        int m=(l+r)/2;
        diff=fabs(s-m);
        if(diff==0)
            return 0;
        return guess(l,r,s);
    }
    else
    {
        int m1=l+(r-l+1)/4,m2=l+(3*(r-l+1))/4,m=(l+r)/2;
        int d1=fabs(s-m1),d2=fabs(s-m2);
        if(d1==0 || d2==0)
            return 1;
        if(d1<=diff)
                return 1+guess(l,m-1,s);
        else
        {
            if(d2>d1)
                return 2+guess(l,m-1,s);
            else
                return 2+guess(m+1,r,s);
        }

    }
}


