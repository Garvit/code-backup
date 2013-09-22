#include<stdio.h>
#include<stdbool.h>

int ans[10]={9,81,648,4536,27216,136080,544320,1632960,3265920,3265920};

long long int inline scan()
{
    long long int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N;
}


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
	bool equal[20]={0};
	bool d[10]={0};
	int digit,flag=0,last,limit,j,part,less,z;
	while(n>0)
	{
		digit=n%10;
		if(k!=0)
			d[digit]=1;
		digits[k++]=digit;
		n=n/10;
	}
	for(i=k-2;i>=0;i--)
	{
		for(j=k-1;j>i;j--)
		{
			if(digits[i]==digits[j])
			{
				equal[i]=true;
				break;
			}
		}
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
	for(i=1;i<=k-1;i++)
	{
		last=digits[k-1-i];
		if(equal[k-i])
		{
			flag=1;
			break;
		}
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
	if(!equal[0] && flag==0)
	   a=a+1;

	return a;
}

int main()
{
	long long int t,l,r,a,b,fin;
	t=scan();
	while(t--)
	{
		l=scan();
		r=scan();
		a=helper(l-1);
		b=helper(r);
		fin=b-a;

		printf("%lld\n",fin);
	}
	return 0;
}
