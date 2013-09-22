#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* add(char* a,char* b)
{
    int l1=strlen(a),l2=strlen(b),i=0,k=0;
    char t,carry=0;
    char *ans=calloc(l1+l2,sizeof(char));
    char *ret=calloc(l1+l2,sizeof(char));
    while(l1>0 && l2>0)
    {
        t=a[l1-1]-48+b[l2-1]-48+carry; carry=0;
        if(t>=10)
        {
            carry=1; t=t-10;
        }
        ans[i]=t+48;
        l1--;l2--;i++;
    }
    if(l1==0)
    {
        while(l2>0)
        {
            t=b[l2-1]-48+carry; carry=0;
            if(t>=10)
            {
                carry=1;t=t-10;
            }
            ans[i]=t+48;i++;l2--;
        }
    }
    else if(l2==0)
    {
        while(l1>0)
        {
            t=a[l1-1]-48+carry;
            carry=0;
            if(t>=10)
            {
                carry=1;t=t-10;
            }
            ans[i]=t+48;i++;l1--;
        }
    }
    if(carry==1)
    {
        ans[i]=carry+48;
        i++;
    }
    while(i>0)
    {
        ret[k++]=ans[i-1];
        i--;
    }
    ret[k]='\0';
    return ret;
}
char *mulhelp(char* a,char b)
{
    int x=b-'0',i,l1=strlen(a);
    char *ans=calloc(l1+1,sizeof(char));
    ans[0]='0';ans[1]='\0';
    for(i=1;i<=x;i++)
    {
        ans=add(ans,a);
    }
    return ans;
}
char* mul(char *a,char* b)
{
    int l1=strlen(a),l2=strlen(b),i=0,k;
    char *ans=calloc(l1+l2,sizeof(char));
    ans[0]='0';
    ans[1]='\0';
    if(l1>=l2)
    {
        i=0;
        while(l2>0)
        {
            if(b[l2-1]!='0')
            {
                char *t=mulhelp(a,b[l2-1]);
                char z[]="0";
                for(k=1;k<=i;k++)
                {
                    t=strcat(t,z);
                }
                ans=add(ans,t);
            }
            i++;l2--;
        }
    }
    else
    {
        i=0;
        while(l1>0)
        {
            if(a[l1-1]!='0')
            {
                char *t=mulhelp(b,a[l1-1]);
                char z[]="0";
                for(k=1;k<=i;k++)
                {
                    t=strcat(t,z);
                }
                ans=add(ans,t);
            }
            i++;l1--;
        }
    }
    return ans;
}
int inline scan()
{
    int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}

int main()
{
    int t,n;
    char str[20];
    char *t1,*t2;
    long long int num,ans;
    t=scan();
    while(t--)
    {
        scanf("%s",str);
        n=atoi(str);
        t1=mul(str,str);
        t2=mul(t1,str);
        ans=(num*num*num)/2+(3*num*num)/2+num;
        printf("%lld\n",ans);
    }
    return 0;
}
