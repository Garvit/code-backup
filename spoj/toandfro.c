#include<stdio.h>
#include<string.h>

int main()
{
    int n,l,i,j,q,rem,k;
    char str[220];
    char **arr;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;

        scanf("%s",str);
        l=strlen(str);
        q=l/n;

        //rem=l-n*q;
        arr=malloc(q*sizeof(char*));
        for(i=0;i<q;i++)
        {
            arr[i]=malloc(n*sizeof(char));
        }
        k=0;
        for(i=0;i<q;i++)
        {
            if(i%2==0)
            {
                for(j=0;j<n;j++)
                {
                    arr[i][j]=str[k++];
                }
            }
            else
            {
                for(j=n-1;j>=0;j--)
                {
                    arr[i][j]=str[k++];
                }
            }
        }

        k=0;
        for(j=0;j<n;j++)
        {
            for(i=0;i<q;i++)
            {
                printf("%c",arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
