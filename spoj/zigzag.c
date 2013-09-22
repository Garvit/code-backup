#include<stdio.h>
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

int main()
{
    int k,i,posi=0,posj=0;
    long long int ans=1,first,real,diff,n,sum;
    n=scan();
    k=scan();
    char *str=malloc(k*sizeof(char));
    scanf("%s",str);
    sum=n*(n+1)/2.0;

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='U')
        {
            posi--;
        }
        else if(str[i]=='D') posi++;
        else if(str[i]=='L') posj--;
        else if(str[i]=='R') posj++;
        if(posi+posj==n-1)
        {
            first=sum-n;

            if(n%2==0)
            {
                ans+=first+posi+1;
            }
            else
            {
                ans+=first+n-posi;
            }
        }
        else if(posi+posj<n-1)
        {
            real=posi+posj;
            first=real*(real+1)/2.0;
            if((real+1)%2==0)
            {
                ans+=first+posi+1;
            }
            else
            {
                ans+=first+posj+1;
            }

        }
        else
        {
            real=posi+posj;
            diff=real-n+1;
            first=sum+n*(n-1)/2.0 - (n-diff)*(n-diff+1)/2.0;
            if((real+1)%2==0)
            {
                ans+=first+n-posj;
            }
            else
            {
                ans+=first+n-posi;
            }
        }
    }

    printf("%lld",ans);
    return 0;
}
