#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
    char str[1000002];
    int t,l,i,j,mid;
    bool all9,flag;
    scanf("%d",&t);
    while(t--)
    {
        flag=1;all9=1;
        scanf("%s",str);
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            if(str[i]!='9')
            {
                all9=0;
                break;
            }
        }
        if(all9==1)
        {
            printf("1");
            for(i=1;i<l;i++)
                printf("0");
            printf("1");
        }
        else
        {
            for(j=l/2-1;j>=0;j--)
            {
                if(str[j]>str[l-1-j])
                {
                    flag=0; break;
                }
                else if(str[j]<str[l-1-j])
                {
                    flag=1; break;
                }
            }
            if(j==-1 || flag==1)
            {
                if(l%2==0) mid=l/2-1;
                else    mid=l/2;

                for(i=mid;i>=0;i--)
                {
                    if(str[i]!='9')
                    {
                        str[i]+=1;
                        break;
                    }
                    else
                    {
                        str[i]='0';
                    }
                }

            }
            for(i=mid;i>=0;i--)
            {
                str[l-1-i]=str[i];
            }

            printf("%s",str);
        }
        printf("\n");
    }


}

