#include<stdio.h>
#include<string.h>

char trans[28];
char str[110];
int main()
{
    int t,l,i,p;
    scanf("%d",&t);
    scanf("%s",trans);
    while(t--)
    {
        scanf("%s",str);
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]=='_')
            {
                printf(" ");
            }
            else if(str[i]>='a' && str[i]<='z')
            {
                printf("%c",trans[str[i]-97]);
            }
            else if(str[i]>='A' && str[i]<='Z')
            {
                printf("%c",trans[str[i]-65]-32);
            }
            else
            {
                printf("%c",str[i]);
            }

        }
        printf("\n");
    }
    return 0;
}
