#include<stdio.h>
#include<string.h>

int main()
{
    int t,l1,l2,i,j,flag;
    char s1[25010],s2[25010];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",&s1,&s2);
        l1=strlen(s1);
        l2=strlen(s2);
        flag=0;
        if(l1<l2)
        {
            i=0;
            for(j=0;j<l2;j++)
            {
                if(s1[i]==s2[j])
                {
                    i++;
                }
                if(i==l1)
                {
                    printf("YES\n");
                    flag=1;
                    break;
                }
            }
        }
        else
        {
            i=0;
            for(j=0;j<l1;j++)
            {
                if(s2[i]==s1[j])
                {
                    i++;
                }
                if(i==l2)
                {
                    printf("YES\n");
                    flag=1;
                    break;
                }
            }
        }
        if(!flag) printf("NO\n");
    }
    return 0;
}
