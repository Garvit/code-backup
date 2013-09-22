#include<stdio.h>

int mod(char s[],int a)
{
    int rem=0,i;

    for(i=0;s[i];i++)
    {
        rem=10*rem+s[i]-'0';
        rem=rem%a;
    }
    return rem;
}

int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}


int main()
{
    int t,a;
    char b[256];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&a,b);
        if(a==0)
            printf("%s\n",b);
        else if(a==1)
             printf("1\n");
        else
             printf("%d\n",gcd(a,mod(b,a)));
    }
    return 0;
}
