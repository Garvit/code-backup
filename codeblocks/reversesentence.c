#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
main()
{
    char *s=calloc(MAX,sizeof(char));
    //char* s1=&s[0];
    //size_t n=1000;
    //getline(s1,&n,stdin);
    //scanf("%s",s);
    int z=0;
    char c;
    while((c=getchar())!='\n')
    {
        s[z++]=c;
    }
    s[z]='\0';
    //s=fgets(s,MAX,stdin);
    int l=strlen(s);
    //printf("%d\n",l);
    int i,end=l-1,start=0;
    for(i=l-1;i>=0;i--)
    {
        char c=' ';
        if(s[i]==c)
        {
            //8printf("ok");
            int j;
            for(j=i+1;j<=end;j++)
            {
                printf("%c",s[j]);
            }
            printf("%c",' ');
            end=i-1;
        }
        else if(i==0)
        {
            int j;
            for(j=i;j<=end;j++)
            {
                printf("%c",s[j]);
            }
        }
    }
}
