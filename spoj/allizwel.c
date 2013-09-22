#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool mem[110][110];
char arr[110][110];
bool eval(int i,int j,int r,int c,int n)
{
    if(n==10) return true;
    mem[i][j]=1;
    char next;
    switch(n)
    {
        case 1:
        case 2:
            next='L';
            break;
        case 3:
            next='I';
            break;
        case 4:
        case 5:
            next='Z';
            break;
        case 6:
            next='W';
            break;
        case 7:
            next='E';
            break;
        case 8:
        case 9:
            next='L';
            break;
    }
    if(i>0)
    {
        if(j>0 && mem[i-1][j-1]==0 && arr[i-1][j-1]==next){
             bool a=eval(i-1,j-1,r,c,n+1);
             if(a) return a;
              }
        if(mem[i-1][j]==0 && arr[i-1][j]==next){
             bool a=eval(i-1,j,r,c,n+1);
             if(a) return a;
              }
        if(j<c-1 && mem[i-1][j+1]==0 && arr[i-1][j+1]==next){
             bool a=eval(i-1,j+1,r,c,n+1);
             if(a) return a;
              }
    }
    if(i<r-1)
    {
        if(j>0 && mem[i+1][j-1]==0 && arr[i+1][j-1]==next){
             bool a=eval(i+1,j-1,r,c,n+1);
             if(a) return a;
              }
        if(mem[i+1][j]==0 && arr[i+1][j]==next){
             bool a=eval(i+1,j,r,c,n+1);
             if(a) return a;
              }
        if(j<c-1 && mem[i+1][j+1]==0 && arr[i+1][j+1]==next){
             bool a=eval(i+1,j+1,r,c,n+1);
             if(a) return a;
              }
    }
    if(j>0 && mem[i][j-1]==0 && arr[i][j-1]==next){
             bool a=eval(i,j-1,r,c,n+1);
             if(a) return a;
              }
    if(j<c-1 && mem[i][j+1]==0 && arr[i][j+1]==next){
             bool a=eval(i,j+1,r,c,n+1);
             if(a) return a;
              }
    mem[i][j]=0;
    return false;

}
int main()
{
    int t,r,c,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&r,&c);
        char str[110];
        for(i=0;i<r;i++)
        {
            scanf("%s",str);
            for(j=0;j<c;j++)
            {
                arr[i][j]=str[j];
                mem[i][j]=0;
            }
        }
        if(r*c<10) printf("NO\n");
        else
        {
            bool ans=false;
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(arr[i][j]=='A')
                    {
                        mem[i][j]=1;
                        ans=eval(i,j,r,c,1);
                        if(ans) break;

                        mem[i][j]=0;
                    }
                }
                if(ans) break;
            }
            if(ans) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
