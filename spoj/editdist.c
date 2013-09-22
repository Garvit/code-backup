#include<stdio.h>
#include<string.h>


int main()
{
    char str[1002];
    while(scanf("%s",str)!=EOF)
    {
        int l=strlen(str),i,val1=0,val2=0;
        if(str[0]>='a' && str[0]<='z')
        {
            val1=0;val2=1;
        }
        else
        {
            val1=1;val2=0;
        }
        for(i=1;i<l;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                if(i%2==0) val2++;
                else val1++;
            }
            else
            {
                if(i%2==0) val1++;
                else val2++;
            }
        }
        printf("%d\n",(val1>val2)?val2:val1);
    }
    return 0;
}
