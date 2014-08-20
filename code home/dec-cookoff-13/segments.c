#include<stdio.h>

int a[1000][2];
char str[8000010];
int main()
{
    int t,i,n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a[i][0],&a[i][1]);
        }
        int l=a[0][0],r=a[0][1],k=0;

        for(i=1;i<n;i++)
        {
            while(l>a[i][0])
            {
                str[k++]='L';
                str[k++]='-';
                l--;
            }
            while(l!=a[i][0])
            {
                if(l+1==r){ str[k++]='R';
                str[k++]='+'; r++; }
                else { str[k++]='L';
                str[k++]='+'; l++;}
            }
            while(r!=a[i][1])
            {
                str[k++]='R';
                if(r>a[i][1]){
                    str[k++]='-'; r--; }
                else{
                    str[k++]='+';
                    r++;}
            }
        }
        printf("%d\n",k/2);
        printf("%s\n",str);
        memset(str,'\0',sizeof(str));
    }
    return 0;
}
