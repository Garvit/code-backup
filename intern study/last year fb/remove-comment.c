#include<stdio.h>

int main()
{
    FILE *fp=fopen("inp.txt","r");
    char ch;
    int comment=0,quote=0;
    while((ch=getc(fp))!=EOF)
    {
        if(quote==1)
        {
            printf("%c",ch);
            if(ch=='"') quote=0;
        }
        else
        {
            if(comment==0)
            {
                if(ch=='"')
                {
                    quote=1;
                    printf("%c",ch);
                    continue;
                }
                else if(ch=='/')
                {
                    char ch1=getc(fp);
                    if(ch1==EOF) {printf("%c",ch); break;}
                    else if(ch1=='/')
                        comment=1;
                    else if(ch1=='*')
                    {
                        comment=2;
                    }
                    else
                    {
                        printf("%c%c",ch,ch1);
                    }

                }
                else
                {
                    printf("%c",ch);
                }
            }
            else if(comment==1)
            {
                if(ch=='\n')
                {
                    printf("%c",ch);
                    comment=0;
                }
            }
            else if(comment==2)
            {
                if(ch=='*')
                {
                    char ch1=getc(fp);
                    if(ch1==EOF) {break;}
                    if(ch1=='/')
                    {
                        comment=0;
                    }
                }
            }
        }
    }
    fclose(fp);
    return 0;
}
