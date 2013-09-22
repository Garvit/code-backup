#include<stdio.h>
#include<string.h>

int get_palin(char *c,int i,int n)
{
    if(i>=0)
    {
        if(c[i]==c[n-i-1])
            return get_palin(c,i-1,n);
        if(c[i]<c[n-i-1])
                return 1;
        else
                 return 2;

    }
    return 1;
}
main()
{
    char c[1000];
    scanf("%s",c);
    int n=strlen(c);
    //printf("%d\n",n);
    int mid=n%2? n/2 : n/2-1;
    int s=get_palin(c,mid,n);
    //int s=1;
    //printf("%d",s);
    int flag=0;
    switch(s)
    {
        case 1:
            if(c[mid]=='9')
            {
                c[mid]='0';
                int i=mid-1;;
                while(i>=0)
                {
                    if(c[i]!='9')
                    {
                        c[i]++;
                        break;
                    }
                    else
                        c[i]='0';
                    i--;
                }
                if(i==-1)
                    flag=1;
            }
            else
                c[mid]++;
            break;

    }
    if(flag==1)
        printf("%c",'1');
    int i;
    for(i=0;i<=mid;i++)
        printf("%c",c[i]);
    for(i=mid+1;i<n;i++)
           printf("%c",c[n-1-i]);
    if(flag==1)
        printf("\b%c",'1');
}
