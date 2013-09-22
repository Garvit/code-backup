#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10000000

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
    int t,n,num,even,c,i,p;
    t=scan();
    while(t--)
    {
        n=scan();
        num=n;
        even=0;
        if(num%2==0){
            c=0;
            while(num%2==0)
            {
                c++;
                num/=2;
            }
            if(c%2==0) even++;
            else even--;
            }
        for(i=3;i<=sqrt(n);i+=2)
        {
            if(num==1) break;

            if(num%i==0){
            c=0;
            while(num%i==0)
            {
                c++;
                num/=i;
            }
            if(c%2==0) even++;
            else even--;
            }

        }
        if(num!=1) even--;

        if(even>0) printf("Psycho Number\n");
        else printf("Ordinary Number\n");

    }
    return 0;
}
