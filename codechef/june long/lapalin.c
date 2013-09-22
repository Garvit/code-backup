#include<stdio.h>
#include<string.h>

int main()
{
    int t,l,i;
    char s[1010];
    int arr[26];
    scanf("%d",&t);
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        scanf("%s",s);
        int l=strlen(s);
        for(i=0;i<l/2;i++)
        {
            arr[s[i]-'a']++;
        }
        for(i=(l+1)/2;i<l;i++)
        {
            arr[s[i]-'a']--;
        }
        for(i=0;i<26;i++)
        {
            if(arr[i]!=0)
            {
                printf("NO\n");
                break;
            }
        }
        if(i==26) printf("YES\n");


    }
    return 0;
}
