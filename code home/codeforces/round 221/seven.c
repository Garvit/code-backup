#include<stdio.h>
#include<string.h>

char str[1000010];
int num[10];
int main()
{
    int i,l,mod,j;
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        num[str[i]-'0']++;
    }
    num[1]--;
    num[6]--;
    num[8]--;
    num[9]--;
    mod=0;
    for(i=1;i<=9;i++)
    {
        for(j=0;j<num[i];j++)
        {
            mod=(mod*10+i)%7;
            printf("%d",i);
        }
    }
    mod=(mod*10)%7;
    mod=(mod*10)%7;
    mod=(mod*10)%7;
    mod=(mod*10)%7;
    if(mod==0) printf("1869");
    else if(mod==1) printf("1896");
    else if(mod==2) printf("1986");
    else if(mod==3) printf("1698");
    else if(mod==4) printf("6198");
    else if(mod==5) printf("1689");
    else if(mod==6) printf("1968");
    for(i=0;i<num[0];i++) printf("0");

}
