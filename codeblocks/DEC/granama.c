#include<stdio.h>
#include<string.h>
int a[26];
int b[26];
char r[1010];
char s[1010];

int main()
{
    int t,flag,l1,l2,i;

    scanf("%d",&t);
    while(t--)
    {
        flag=1;
        scanf("%s %s",r,s);
        l1=strlen(r);
        l2=strlen(s);
        for(i=0;i<l1;i++)
        {
            a[r[i]-97]++;
        }
        for(i=0;i<l2;i++)
        {
            b[s[i]-97]++;
        }
        for(i=0;i<26;i++)
        {
            if(a[i]==0 && b[i]!=0)
            {
                printf("YES\n");
                break;
            }
            else if(b[i]==0 && a[i]!=0)
            {
                printf("YES\n");
                break;
            }

        }
        if(i==26)
        {
            for(i=0;i<26;i++)
            {
                if(a[i]!=b[i])
                {
                    printf("NO\n");
                    break;
                }
            }
            if(i==26)
                printf("YES\n");
        }
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
}
