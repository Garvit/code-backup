#include<stdio.h>
#include<string.h>
int end;
int eval(char *str,int s)
{

    if(str[s]=='l'){ end=s; return 0;}

    int left=eval(str,s+1);
    int right=eval(str,end+1);
    int m=left>right?left:right;
    return 1+m;

}
int main()
{
    int t,l,i;
    char str[10010];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        printf("%d\n",eval(str,0));
    }
    return 0;
}
