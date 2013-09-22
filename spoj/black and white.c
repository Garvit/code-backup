#include<stdio.h>
#include<string.h>

int main()
{
    char s[510],t[510];
    int i,count,flag;
    while(1)
    {
        scanf("%s %s",s,t);
        if(s[0]=='*') break;
        count=0;flag=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]!=t[i])
            {
                flag=1;
            }
            else
            {
                if(flag==1){ count++; flag=0; }
            }
        }
        if(flag==1) count++;
        printf("%d\n",count);
    }
    return 0;
}
