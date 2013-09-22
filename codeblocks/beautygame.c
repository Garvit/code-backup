#include<stdio.h>

main()
{
 unsigned int t,n,nz=0,turns=0;
 scanf("%d",&t);
 while(t--)
 {
     nz=0,turns=0;
     scanf("%d",&n);
     while(n>=1)
     {
         if(n&1)
            turns+=nz;
         else
            nz++;
         n>>=1;

     }
     if(turns%2==0)
        printf("Second player\n");
     else
        printf("First Player\n");

 }
}
