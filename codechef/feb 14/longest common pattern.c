#include<stdio.h>
#include<string.h>

char a[10010],b[10010];
int count1[62],count2[62];
int main()
{
    int t,i,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",b);
        ans=0;
        int l1=strlen(a),l2=strlen(b);
        for(i=0;i<l1;i++)
        {
            if(a[i]>='0' && a[i]<='9')
                count1[a[i]-'0']++;
            else if(a[i]>='a' && a[i]<='z')
                    count1[a[i]-'a'+10]++;
            else
                    count1[a[i]-'A'+36]++;
        }
        for(i=0;i<l2;i++)
        {
            if(b[i]>='0' && b[i]<='9')
                count2[b[i]-'0']++;
            else if(b[i]>='a' && b[i]<='z')
                    count2[b[i]-'a'+10]++;
            else
                    count2[b[i]-'A'+36]++;
        }
        for(i=0;i<62;i++)
        {
            ans+=(count1[i]<count2[i])?count1[i]:count2[i];
            count1[i]=0;
            count2[i]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
