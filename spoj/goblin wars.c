#include<stdio.h>
#include<string.h>

char arr[510][510];
char temp[510][510];
int main()
{
    int t,r,c,i,j;
    char str[510];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%s",str);
            for(j=0;j<c;j++)
            {
                arr[i][j]=str[j];
            }
        }
        int flag=0;
        while(1)
        {
            flag=0;
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(arr[i][j]=='.')
                    {

                        char c1='\0';
                        if(i>0 && (arr[i-1][j]>='a' && arr[i-1][j]<='z'))
                        {
                             flag=1;
                            c1=arr[i-1][j];
                        }
                        if(j>0 && (arr[i][j-1]>='a' && arr[i][j-1]<='z'))
                        {
                             flag=1;
                            if(c1=='\0') c1=arr[i][j-1];
                            else if(c1!=arr[i][j-1]){ temp[i][j]='*'; continue;}
                        }
                        if(i<r-1 && (arr[i+1][j]>='a' && arr[i+1][j]<='z'))
                        {
                             flag=1;
                            if(c1=='\0') c1=arr[i+1][j];
                            else if(c1!=arr[i+1][j]){ temp[i][j]='*'; continue;}
                        }
                        if(j<c-1 && (arr[i][j+1]>='a' && arr[i][j+1]<='z'))
                        {
                             flag=1;
                            if(c1=='\0') c1=arr[i][j+1];
                            else if(c1!=arr[i][j+1]){ temp[i][j]='*'; continue;}
                        }
                        if(c1!='\0') {temp[i][j]=c1;}
                    }
                }
            }
            if(flag==0) break;
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(temp[i][j]!='\0')
                        arr[i][j]=temp[i][j];
                }
            }

            memset(temp,'\0',sizeof(temp));
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%c",arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }
    return 0;
}
