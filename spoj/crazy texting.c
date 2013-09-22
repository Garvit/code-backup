#include<stdio.h>
#include<string.h>
#define MOD 100000007
long long res=0;
int mem[2][400001];
int main()
{
    int t,d,times,l,n,prev,i;

    mem[0][0]=mem[1][0]=1;
    mem[0][1]=mem[1][1]=1;
    mem[0][2]=mem[1][2]=2;
    mem[0][3]=mem[1][3]=4;
    mem[0][4]=mem[1][4]=8;
    for(i=5;i<400001;i++)
    {
        mem[0][i]=(mem[0][i-1]+mem[0][i-2]+mem[0][i-3]+mem[0][i-4]+1)%MOD;
        mem[1][i]=(mem[1][i-1]+mem[1][i-2]+mem[1][i-3]+1)%MOD;
    }

    int arr[]={12,22,32,13,23,33,14,24,34,15,25,35,16,26,36,17,27,37,47,18,28,38,19,29,39,49};
    char str[100010];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        res=1;
        l=strlen(str);
        n=0;d=0;prev=0;
        for(i=0;i<l;i++)
        {
            d=arr[str[i]-'a']%10;
            times=arr[str[i]-'a']/10;
            //printf("%d %d\n",n,times);
            if(d==prev || i==0)
            {
                n+=times;
                prev=d;
            }
            else
            {
                if(prev==7 || prev==9)
                    res=(res*mem[0][n])%MOD;
                else
                    res=(res*mem[1][n]%MOD);
                n=times;
                prev=d;

            }
        }
        if(prev==7 || prev==9)
            res=(res*mem[0][n])%MOD;
        else
            res=(res*mem[1][n]%MOD);
        printf("%lld\n",res);
    }
    return 0;
}
