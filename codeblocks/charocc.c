#include<stdio.h>
#include<string.h>

main()
{
    char s[1000];
    scanf("%s",s);
    int l=strlen(s);
    int i,count=0;
    char c;
    c=s[0];
    count=0;
    printf("%c",c);
    for(i=0;i<l;i++)
    {
        if(s[i]!=c)
        {
            c=s[i];
            if(count!=1)
            printf("%d",count);
            printf("%c",c);
            count=1;

        }
        else
        count++;
    }
    if(count>1)
    printf("%d",count);

}
