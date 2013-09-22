#include<stdio.h>
#include<string.h>
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
    int t,l,i,j,start,end;
    char s[2020];
    char ans[2020];
    t=scan();
    while(t--)
    {
        scanf("%s",s);
        l=strlen(s);
        //printf("%d\n",l);
        end=l-1;
        ans[l]='\0';
        for(i=l-4;i>=0;i--)
        {
            //printf("%d\n",i);
            if((s[i]=='C' || s[i]=='?') && (s[i+1]=='H' || s[i+1]=='?') && (s[i+2]=='E' || s[i+2]=='?') && (s[i+3]=='F' || s[i+3]=='?'))
            {
                ans[i]='C';
                ans[i+1]='H';
                ans[i+2]='E';
                ans[i+3]='F';
                //printf("%d\n",i);
                end=i-1;
                i-=3;

                //printf("%d\n",i);
            }
            else
            {
                if(s[i+3]=='?')
                    ans[i+3]='A';
                 else
                    ans[i+3]=s[i+3];
                end=i+2;
            }
            //printf("%s\n",ans);
        }
        for(i=0;i<=end;i++)
        {
            if(s[i]=='?')
                ans[i]='A';
            else
                ans[i]=s[i];
        }
        ans[l]='\0';
        printf("%s\n",ans);
        memset(ans,0,sizeof(ans));

    }
}
