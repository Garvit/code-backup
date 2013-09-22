#include<stdio.h>
#include<string.h>

main()
{
    char s[1000];
    char a[1000];
    int z=0;
    char c;
    while((c=getchar())!='\n')
    {
        s[z++]=c;
    }
    s[z]='\0';
    //scanf("%s",s);
    int l=strlen(s);
    int i=0,k=0;
    while(s[k]!='\0')
    {
        if(s[k]==' ')
        {
            a[i++]=s[k];
            k=k+1;
            while(s[k]==' ')
            {
                k=k+1;
            }
        }
        else
        {
            a[i++]=s[k];
            k=k+1;
        }
    }
    a[i]='\0';
    printf("%s",a);
}
