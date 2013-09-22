#include<stdio.h>
#include<string.h>

main()
{
    char *s=calloc(1000,sizeof(char));
    char *p=calloc(1000,sizeof(char));
    scanf("%s",p);
    scanf("%s",s);
    int len=strlen(s);
    int l=strlen(p);
    char* c=strstr(s,p);
    if(c==s)
    {
        printf("X");
        s=s+l;
        c=strstr(s,p);
    }

    while(c!=NULL)
    {
        if(c==s)
        {
            s=s+l;

        }
        else {
            while(s!=c)
        {
            printf("%c",*s);
            s=s+1;
        }

        printf("X");
        s=s+l;
        }


        c=strstr(s,p);
        //printf("%s\n",c);
    }
    while(*s!='\0')
    {
        printf("%c",*s);
        s=s+1;
    }
    //c=c+l;
    //char* d=strstr(c,p);

    //printf("%s",d);
}
