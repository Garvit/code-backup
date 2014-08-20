#include<stdio.h>
#include<string.h>
char str[1000010];
int main()
{

    int i,l,p=0;
    long long a1=0,a2=0;
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        if(str[i]=='^') break;
    }
    p=i;
    for(i=p-1;i>=0;i--)
    {
        if(str[i]>='1' && str[i]<='9')
        {
            a1+=(str[i]-48)*(p-i);
        }
    }
    for(i=p+1;i<l;i++)
    {
        if(str[i]>='1' && str[i]<='9')
        {
            a2+=(str[i]-48)*(i-p);
        }
    }
    if(a1>a2) printf("left");
    else if(a1<a2) printf("right");
    else printf("balance");
    return 0;
}
