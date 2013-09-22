#include<stdio.h>
#include<string.h>

int main()
{
    int t,l,i;
    char str[20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        l=strlen(str);
        for(i=0;i<l/2;i++)
        {
            if(str[i]!=str[l-1-i])
                break;
        }
        if(i!=l/2)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}
