#include<stdio.h>
#include<stdbool.h>
#include<string.h>
long long int inline scan()
{
    long long int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}
int arr[100001];
int main()
{
    long long int t,n,k,a,b,c,r,i,z,j,temp;
    long long int *m;
    t=scan();
    for(z=1;z<=t;z++)
    {
        n=scan();
        k=scan();
        m=calloc(2*k+1,sizeof(long long int));
	a=scan();
        b=scan();
        c=scan();
        r=scan();
        m[0]=a;
	if(a<=k)
        	arr[a]=1;
        for(i=1;i<k;i++)
        {
            m[i]=(b*m[i-1]+c)%r;
            if(m[i]<=k)
                arr[m[i]]++;
        }
	for(i=k;i<n && i<=2*k;i++)
        {
            j=0;
            while(1)
            {
                if(arr[j]==0)
                {
                    break;
                }
                j++;
            }
            m[i]=j;
            arr[j]++;
            if(m[i-k]<=k)
                arr[m[i-k]]--;
        }
	if( n<= 2*k+1)
        {
            printf("Case #%lld: %lld\n",z,m[n-1]);
        }
        else
        {
            temp=(n-k)%(k+1);
            if(temp==0)
                printf("Case #%lld: %lld\n",z,m[2*k]);
            else
                printf("Case #%lld: %lld\n",z,m[k-1+temp]);
        }
        memset(arr,0,sizeof(arr));
    }

    return 0;


}
