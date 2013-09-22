#include<stdio.h>
#include<stdbool.h>

int ans[10]={9,81,648,4536,27216,136080,544320,1632960,3265920,3265920};
long long int helper(long long int n)
{
    if(n==0)
        return 0;
    int k=0,i;
    long long int a=0;

    if(n>=10000000000ull)
    {
        for(i=0;i<10;i++)
        {
            a+=ans[i];
        }
        return a;
    }
    int digits[20];
    bool d[10]={0};
    int digit,last,limit,j,part,less,z;
    while(n>0)
    {
        digit=n%10;
        if(k!=0)
            d[digit]=1;
        digits[k++]=digit;
        n=n/10;
    }
    if(k==1)
        return digits[0];
    //printf("k: %d\n",k);
    for(i=0;i<k-1;i++)
    {
        a+=ans[i];
    }
    //printf("%lld\n",a);
        last=digits[k-1];
        j=9;limit=k-1;
        part=1;
        while(limit--)
        {
            part*=j;
            j--;
        }
        a+=(last-1)*part;
    //printf("%lld\n",a);
    for(i=1;i<k-1;i++)
    {
        last=digits[k-1-i];
        j=9-i;limit=k-1-i;
        less=0;
        for(z=0;z<i;z++)
        {
            if(digits[k-1-z]<last)
                less++;
        }
        part=1;
        while(limit--)
        {
            part*=j;
            j--;
        }
        a+=(last-less)*part;
    }
    //printf("%lld\n",a);
    last=digits[0];

    //printf("last: %d\n",last);
    if(k>1){
    for(i=0;i<=last;i++)
    {
        if(d[i]==0)
            a++;

    }
    }
    //printf("%lld\n",a);
    //printf("\n");
    return a;
}
bool check(long long int n)
{
    int digits[10]={0};
    int digit;
    while(n>0)
    {
        digit=n%10;
        if(digits[digit]==1)
            return false;
        else
            digits[digit]=1;

       n=n/10;
    }
    return true;
}
int main()
{
    long long int t,l,r,a,b,fin;
    scanf("%lld",&t);
    while(t--)
    {
        fin=0;
        scanf("%lld %lld",&l,&r);
        if(l<9876543211)
        {
            if(l<r)
            {
                a=helper(l-1);
                b=helper(r);
                fin=b-a;
            }
        }
        //if(check(l))
         //   fin++;
        //printf("%lld %lld\n",a,b);
        printf("%lld\n",fin);
    }
    return 0;
}

