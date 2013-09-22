#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int main()
{
    char str[1000002];
    int t,n,l,temp,ans,flag,i,j;
    char mid,carry;
    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        scanf("%s",str);
        l=strlen(str);
        if(l%2==1)
        {
            mid=str[l/2];
            //printf("mid: %c\n",mid);
            for(j=l/2-1;j>=0;j--)
            {
                //printf("%c %c\n",str[i],str[l-i-1]);
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
                if(mid!='9')
                {
                    mid=mid+1;
                    for(i=0;i<l/2;i++)
                        printf("%c",str[i]);
                    printf("%c",mid);
                    for(i=l/2-1;i>=0;i--)
                        printf("%c",str[i]);
                }
                else
                {
                    mid='0';
                    for(i=l/2-1;i>=0;i--)
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
                    if(i==-1)
                    {
                        printf("1");
                        for(i=1;i<l;i++)
                            printf("0");
                        printf("1");
                    }
                    else
                    {
                        for(i=0;i<l/2;i++)
                        {
                            printf("%c",str[i]);
                        }
                        printf("0");
                        for(i=l/2-1;i>=0;i--)
                        {
                            printf("%c",str[i]);
                        }
                    }
                }
            }
            else if(flag==0)
            {
                for(i=0;i<=l/2;i++)
                {
                    printf("%c",str[i]);
                }

                for(i=l/2-1;i>=0;i--)
                {
                    printf("%c",str[i]);
                }
            }

        }
        else
        {
            for(j=l/2-1;j>=0;j--)
            {
                //printf("%c %c\n",str[i],str[l-i-1]);
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
                for(i=l/2-1;i>=0;i--)
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
                if(i==-1)
                {
                    printf("1");
                    for(i=1;i<l;i++)
                        printf("0");
                    printf("1");
                }
                else
                {
                    for(i=0;i<l/2;i++)
                    {
                        printf("%c",str[i]);
                    }
                    for(i=l/2-1;i>=0;i--)
                    {
                        printf("%c",str[i]);
                    }
                }
            }
            else if(flag==0)
            {
                for(i=0;i<l/2;i++)
                {
                    printf("%c",str[i]);
                }

                for(i=l/2-1;i>=0;i--)
                {
                    printf("%c",str[i]);
                }
            }
        }

        printf("\n");
    }


}
