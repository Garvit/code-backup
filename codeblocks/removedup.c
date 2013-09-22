#include<stdio.h>
#include<ctype.h>
#include<string.h>

void removedup1(char c[])
{
    unsigned int checker=0;
    int l=strlen(c);
    char *n=(char *)calloc(l,sizeof(char));
    int i,k=0;
    for(i=0;i<l;i++)
    {
        int val=tolower(c[i])-'a';
        if((checker & 1<<val)>0)
        {
                continue;
        }
        else{
                checker |= (1<< val);
                n[k]=c[i];
                k++;
        }
    }
        printf("%s\n",n);
}
void removedup2(char s[])
{
    int l=strlen(s);
    int tail=1,i;
    for(i=1;i<l;i++)
    {
        int j;
        for(j=0;j<tail;j++)
        {
            if(s[j]==s[i])
                break;
        }
        if(j==tail)
        {
            s[tail]=s[i];
            tail++;
        }
    }
    s[tail]='\0';
    printf("%s\n",s);

}
main()
{
    char c[]="9359176002";
    //removedup1(c);
    removedup2(c);

}

