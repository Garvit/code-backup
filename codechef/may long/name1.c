#include<stdio.h>
#include<string.h>

int count[26];
int main()
{
    int t,n,l,flag,i;
    char a[40010],b[40010],c[40010];
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%s%s",a,b);
        l=strlen(a);
        for(i=0;i<l;i++)
        {
            count[a[i]-'a']++;
        }
        l=strlen(b);
        for(i=0;i<l;i++)
        {
            count[b[i]-'a']++;
        }
        /*for(i=0;i<26;i++)
        {
            printf("%d ",count[i]);
        }
        printf("\n");
        */
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",c);
            l=strlen(c);
            for(i=0;i<l && flag==0;i++)
            {
                if(count[c[i]-'a']==0)
                {
                    flag=1;
                }
                count[c[i]-'a']--;
            }
        }

        if(flag==0)
            printf("YES\n");
        else printf("NO\n");
        memset(count,0,sizeof(count));
    }
    return 0;
}
