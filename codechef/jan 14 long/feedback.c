#include<stdio.h>
#include<string.h>
char str[100010];
int main()
{
    int t,i,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        l=strlen(str);
        int s=0;
        for(i=1;i<l;i++)
        {
            if(str[i]!=str[i-1])
                s++;
            else s=0;

            if(s==2) break;
        }
        if(i==l) printf("Bad\n");
        else printf("Good\n");
    }
    return 0;
}
