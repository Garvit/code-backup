#include<stdio.h>
#include<string.h>
#include<math.h>
int arr[52];
int main()
{
    int t,l,i,ans;
    char str[210];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        l=strlen(str);
        ans=0;
        for(i=0;i<l;i++)
        {
            if(str[i]>='a' && str[i]<='z')
            {
                arr[str[i]-'a']++;
            }
            else
            {
                arr[str[i]-'A'+26]++;
            }
        }
        for(i=0;i<52;i++)
        {
            ans+=ceil(arr[i]/2.0);
        }
        printf("%d\n",ans);
        memset(arr,0,sizeof(arr));
    }
}
