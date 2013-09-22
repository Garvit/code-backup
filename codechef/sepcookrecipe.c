#include<stdio.h>
#include<string.h>

int main()
{
    long mod=10000009,l,count;
    int t,i;
    scanf("%d",&t);
    char str[1000000];
    getchar();
    for(i=0;i<t;i++)
    {
        gets(str);
        l=strlen(str);
        int j,flag=0;
        count=1;
        for(j=0;j<l/2;j++)
        {
            //printf("%c %c",str[j],str[l-1-j]);
            if(str[j]=='?' && str[l-1-j]=='?')
                count=(count*26)%mod;

            else if(str[j]!=str[l-1-j] && str[j]!='?' && str[l-1-j]!='?')
            {
                count=0;
                flag=1;

                break;
            }

        }
        if(flag!=1){
        if(l%2!=0)
        {
            if(str[j]=='?')
                count=(count*26)%mod;
        }}
        printf("%ld\n",count);

    }
    return 0;
}
