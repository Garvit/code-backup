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

char* sub(char *a,char *b)
{
    int l1=strlen(a),l2=strlen(b),i=0,k=0,j,flag;

    char *ans=calloc(l1+1,sizeof(char));
    char *ret=calloc(l1+1,sizeof(char));
    while(l2>0)
    {
        if(b[l2-1]<=a[l1-1])
            ans[i]=a[l1-1]-b[l2-1]+48;
        else
        {
            flag=0;
            for(j=l1-2;j>=0;j--)
            {
                if(a[j]>'0') break;
            }
            a[j]--; if(j==0) flag=1;
            for(k=j+1;k<l1-1;k++)
            {
                a[k]='9';
            }
            ans[i]=a[l1-1]+10-b[l2-1]+48;
        }
        //printf("%c %c %c",a[l1-1],b[l2-1],ans[i]);
        i++;l2--;l1--;

    }
    while(l1>flag)
    {
        ans[i++]=a[l1-1];
        l1--;
      //  printf("%c %c",a[l1],ans[i-1]);
    }
    k=0;
    //printf("i: %d\n",i);
    while(i>0)
    {
        ret[k++]=ans[i-1]; i--;
      //  printf("%c",ret[k-1]);
    }
    ret[k]='\0';

    //printf("%s",ret);
    return ret;
}
int main()
{
    int t,i;
    char str1[120],str2[120];
    char *temp;
    for(i=0;i<1;i++)
    {
        scanf("%s",str1);
        scanf("%s",str2);
        temp=sub(str1,str2);
        printf("%s",temp);
    }

    return 0;
}
