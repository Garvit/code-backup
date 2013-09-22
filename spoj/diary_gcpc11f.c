#include<stdio.h>
#include<string.h>
#include<math.h>
int arr[26];
int main()
{
    int t,max,maxp,i,d,l;
    char str[1010];
    char c;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        max=0;l=0;
        c=getchar();
        while(c!='\n')
        {
            str[l++]=c;
            c=getchar();
        }

        for(i=0;i<l;i++)
        {
            //printf("%c",str[i]);
            if(str[i]!=' ')
            {
                int p=str[i]-'A';
                arr[p]++;
                if(arr[p]>max)
                {
                    max=arr[p];
                    maxp=p;
                }
            }
        }
        for(i=0;i<26;i++)
        {
            if(i!=maxp && arr[i]==max)
                break;
        }
        if(i!=26)
        {
            printf("NOT POSSIBLE\n");
            memset(arr,0,sizeof(arr));
            continue;
        }
        d=((maxp-4)+26)%26;
        printf("%d ",d);
        for(i=0;i<l;i++)
        {
            c=(str[i]!=' ')?(((str[i]-'A'-d+26)%26) + 'A'):' ';
            printf("%c",c);
        }
        printf("\n");
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
