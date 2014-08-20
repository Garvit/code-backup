#include<stdio.h>
#include<string.h>

int main()
{
    int t,i,count=0,j,k;
    char str[15];
    short ans[12];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        count=0;
        int flag=0;
        for(i=1;i<=12;i++)
        {
            if(12%i==0)
            {
                for(j=1;j<=12/i;j++)
                {
                    flag=0;
                    for(k=j;k<=12;k+=12/i)
                    {
                        if(str[k-1]!='X'){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){ ans[count++]=i; break;}
                }
            }
        }
        printf("%d",count);
        for(i=0;i<count;i++)
        {
            printf(" %dx%d",ans[i],12/ans[i]);
        }
        printf("\n");
    }
    return 0;
}
