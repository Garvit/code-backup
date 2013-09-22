#include<stdio.h>
#include<string.h>
#define ull unsigned long long int

ull ans,part;
char s[5100];
int main()
{
    int t,len,i,j,nf,ns;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;nf=0;ns=0;part=0;
        scanf("%s",s);
        len=strlen(s);
        if(len==1)
        {
            printf("1\n");
            continue;
        }
        for(i=0;i<len;i++)
        {
            if(s[i]=='4')
                nf++;
            else if(s[i]=='7')
                ns++;
        }
        if(len==ns)
        {
            printf("1\n");
            continue;
        }
        if(len-ns==1)
        {
            printf("%d\n",len-1);
            continue;
        }
        if(len-ns==2)
        {
            printf("%d\n",((n-1)*(n-2)+2)/2);
        }
        part=ns*(n-1)+(n-ns)(n-ns-1);




    }

    return 0;
}
