#include<stdio.h>
#include<string.h>

char str[1000010];
int main()
{
    int t,l,i,count,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        l=strlen(str);
        count=0;ans=0;
        for(i=0;i<l;i++)
        {
            if(str[i]=='<')
                count++;
            else count--;

            if(count<0) break;
            else if(count==0) ans=i+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
