#include<stdio.h>
#include<ctype.h>
#include<string.h>
main()
{
    char c[]="GaRvitg";
    unsigned int checker=0;
    int l=strlen(c);
    int i,f=0;
    for(i=0;i<l;i++)
    {
        int val=tolower(c[i])-'a';
        if((checker & 1<<val)>0)
        {
            printf("not unique");
            f=1;
            break;
        }
        else
                checker |= (1<< val);
    }
    if(f==0)
        printf("unique");

}
