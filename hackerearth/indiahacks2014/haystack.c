#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char pattern[1010];
char text[100010];
int check[26];
int arr[26];

bool func()
{
    int i;
    for(i=0;i<26;i++)
    {
        if(arr[i]!=check[i])
            return false;
    }
    return true;
}
int main()
{
    int t,i,lp,lt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",pattern);
        scanf("%s",text);
        lp=strlen(pattern);
        lt=strlen(text);
        for(i=0;i<lp;i++)
        {
            check[pattern[i]-'a']++;
            if(i<lt)
                arr[text[i]-'a']++;
        }
        if(func()) printf("YES\n");
        else
        {
            for(i=lp;i<lt;i++)
            {
                arr[text[i-lp]-'a']--;
                arr[text[i]-'a']++;
                if(func())
                    break;
            }
            if(i<lt) printf("YES\n");
            else printf("NO\n");
        }
        memset(check,0,sizeof(check));
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
