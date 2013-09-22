#include<stdio.h>
#include<string.h>

int checkanagram(char s[],char t[])
{
    if(strlen(s)!=strlen(t)) return 0;
    int letters[256];
    int i,unique=0,comp=0;
    for(i=0;i<strlen(s);i++)
    {
        if(letters[s[i]]==0) unique++;
        letters[s[i]]++;
    }
    for(i=0;i<strlen(t);i++)
    {
        if(letters[t[i]]==0) return 0;
        letters[t[i]]--;
        if(letters[t[i]]==0) comp++;

        if(comp==unique) return 1;
    }
    return 0;
}
main()
{
    char s[]="sfd";
    char t[]="pot";
    int b=checkanagram(s,t);
    printf("%d",b);
}

