#include<stdio.h>
unsigned long int **ans;
unsigned long int **temp;
unsigned long int **t;
/*unsigned long int findscheme(long n)
{
   if(n==2)
        return 12;
   if(n==3)
        return 24;

   int i;

   temp[0][0]=24;
   temp[0][1]=12;
   temp[1][0]=12;
   temp[1][1]=0;
    t=power(n-3);
    matrixmul(temp,t);
    return t[0][0];
}*/
void matrixmul(unsigned long int **a,unsigned long int **b)
{
   int i,j,k;
   t=malloc(2*sizeof(unsigned long int*));
   for(i=0;i<2;i++)
   {
       t[i]=malloc(2*sizeof(unsigned long int));

   }

    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            t[i][j]=0;
            for(k=0;k<2;k++)
            {
                t[i][j]+=(a[i][k]*b[k][j]);
            }

        }
    }


}
unsigned long int** power(unsigned long int n)
{
    if(n==1)
        return ans;

    unsigned long int **ha=power(n/2);
    matrixmul(ha,ha);

    if(n%2==0)
            return t;
    else{
     matrixmul(t,ans);
     return t;
    }
}

int main()
{
    int test,i;
    ans =malloc(2*sizeof(unsigned long int*));
   for(i=0;i<2;i++)
   {
       ans[i]=malloc(2*sizeof(unsigned long int));

   }
   ans[0][0]=2;
   ans[0][1]=1;
   ans[1][0]=3;
   ans[1][1]=0;
   temp=malloc(2*sizeof(unsigned long int*));
   for(i=0;i<2;i++)
   {
       temp[i]=malloc(2*sizeof(unsigned long int));
   }
   temp[0][0]=24;
   temp[0][1]=12;
   temp[1][0]=12;
   temp[1][1]=0;
   /*temp=power(10);
   printf("%lu ",temp[0][0]);
   printf("%lu ",temp[0][1]);
   printf("%lu ",temp[1][0]);
   printf("%lu ",temp[1][1]);*/
   unsigned long int n;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lu",&n);
        if(n==2)
            printf("12\n");
        else if(n==3)
            printf("24\n");
        else{
            ans=power(n-3);
            matrixmul(temp,ans);
            printf("%lu\n",(t[0][0]%(1000000000+7)));
        }

    }
    return 0;
}
