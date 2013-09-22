#include<stdio.h>
#include<stdbool.h>
#include<math.h>
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

int eval(int n)
{

   int i,ans=n;
   for(i=2;i*i<=n;i++)
   {
       if(n%i==0)
       {
           ans-=ans/i;
           while(n%i==0)
            n=n/i;
       }
   }
   if(n>1)
   {
       ans-=ans/n;
   }
   return ans;
}

int main()
{
    int i,t,n;

    t=scan();
    while(t--)
    {
        n=scan();
        printf("%d\n",eval(n));
    }
    return 0;
}
