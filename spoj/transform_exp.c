#include<stdio.h>
#include<string.h>
char *op[400];

int main()
{
    int t,l,point,i;
    char str[410];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        point=-1;
        l=strlen(str);
        for(i=0;i<l;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                printf("%c",str[i]);
            }
            else if(str[i]==')')
            {
                printf("%c",op[point--]);
            }
            else if(str[i]!='(')
            {
                op[++point]=str[i];
            }
        }
        printf("\n");

    }
}
