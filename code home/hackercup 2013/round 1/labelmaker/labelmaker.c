#include<stdio.h>
#include<string.h>
#define ull unsigned long long
void func(char l[30], ull n , ull mod,int len)
{
    printf("\n%s %llu %llu %d\n",l,n,mod,len);
    if(mod==0) return;
    printf("%c",l[n/mod]);
    func(l,n%mod,mod/len,len);
}

int main()
{
    int t,i,z;
    char l[30];
    long long n,p;
    scanf("%d",&t);
    for(z=1;z<=t;z++)
    {
        scanf("%s %lld",&l,&n);
        int len=strlen(l);
        p=len;
        /*while(n>pow)
        {
            n-=pow;
            pow*=len;
        }*/
        printf("Case #%d: ",z);
        printf("\n%s %lld %lld %d \n",l,n,p,len);
        //func(l,n-1,pow/len,len);
        printf("\n");
    }
    return 0;
}
