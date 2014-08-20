#include<stdio.h>
#include<stdbool.h>

int s1[100000];
int s2[100000];
bool r1[100000];
bool r2[100000];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&s1[i],&s2[i]);
    }
    for(i=0;i<n/2;i++)
    {
        r1[i]=1;r2[i]=1;
    }
    int c=0;
    i=0;j=0;
    while(c<n)
    {
        if(s1[i]<=s2[j]){
            r1[i]=1;
            i++;
        }
        else
        {
            r2[j]=1;
            j++;
        }
        c++;
    }
    for(i=0;i<n;i++)
    {
      printf("%d",r1[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
      printf("%d",r2[i]);
    }
    return 0;
}
