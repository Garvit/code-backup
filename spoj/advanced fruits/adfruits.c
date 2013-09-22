#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int c[110][110];
char b[110][110];
bool mark1[110];
bool mark2[110];
int main()
{
    char str1[110],str2[110];
    int l1,l2,i,j,start1,start2;
    while(scanf("%s %s",str1,str2)!=EOF)
    {
        l1=strlen(str1);
        l2=strlen(str2);

        for(i=0;i<=l1;i++)
            c[i][0]=0;
        for(j=0;j<=l2;j++)
            c[0][j]=0;

        for(i=1;i<=l1;i++)
        {
            for(j=1;j<=l2;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]='a';
                }
                else if(c[i-1][j]>=c[i][j-1])
                {
                    c[i][j]=c[i-1][j];
                    b[i][j]='u';
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    b[i][j]='l';
                }
            }
        }
        i=l1;j=l2;
        while(i!=0 && j!=0)
        {
            if(b[i][j]=='a')
            {

                mark1[i-1]=1;
                mark2[j-1]=1;
                i--;j--;
            }
            else if(b[i][j]=='u')
            {
                i--;
            }
            else
                j--;
        }
        /*for(i=0;i<l1;i++)
            printf("%d",mark1[i]);
        printf("\n");
        for(i=0;i<l2;i++)
            printf("%d",mark2[i]);
        printf("\n");
        */start1=0;start2=0;
        while(start1<l1 || start2<l2)
        {
            for(i=start1;i<l1;i++)
            {
                if(mark1[i])
                    break;

                printf("%c",str1[i]);
            }
            start1=i+1;
            for(j=start2;j<l2;j++)
            {
                if(mark2[j])
                    break;

                printf("%c",str2[j]);
            }
            start2=j+1;
            if(i<l1)
                printf("%c",str1[i]);
            //printf("%d %d",i,j);
        }
        printf("\n");
        memset(c,0,sizeof(c));
        memset(mark1,0,sizeof(mark1));
        memset(mark2,0,sizeof(mark2));
        memset(b,'\0',sizeof(b));
    }
    return 0;
}
