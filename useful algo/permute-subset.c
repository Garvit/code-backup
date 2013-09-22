#include<string.h>
#include<stdio.h>


void permute(char str[],char a[])
{

}
void subset(char str[],char *a)
{
    if(strlen(a)==0) return;

    int i,l=strlen(str);
    for(i=0;i<strlen(a);i++)
    {
        printf("%s%c\n",str,a[i]);
        str[l]=a[i];
        //str[l+1]='\0';
        subset(str,a+i);
    }

}

int main()
{
    char str[]="garvit";
    int l=strlen(str);
    str[l]='a';
    str[l+1]='\0';
   // subset("",str);
    printf("%s",str+1);
    return 0;
}
