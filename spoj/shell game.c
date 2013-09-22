#include<stdio.h>
#include<string.h>
int main()
{
    char pos[10];
    char str1[10],str2[10];
    scanf("%s",pos);
    int n;
    scanf("%d",&n);

    while(n--)
    {
        scanf("%s %s",str1,str2);
        if(strcmp(str1,pos)==0) strcpy(pos,str2);
        else if(strcmp(str1,pos)==0) strcpy(pos,str1);
    }
    if(n!=10){printf("%s",pos);}
    return 0;
}
