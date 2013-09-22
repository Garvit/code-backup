#include<stdio.h>
#include<math.h>

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
    int t,n,flag=0;               //0- boy  1-girl
    long long int k,temp;
    t=scan();
    while(t--)
    {
        n=scan();
        k=scan();
        flag=0;
        if(n==1)
        {
            printf("Male\n");
            continue;
        }
        else if(n==2)
        {
            if(k==1)
                printf("Male\n");
            else printf("Female\n");
            continue;
        }

        temp=k==1?1:ceil(log(k)/log(2));
        //printf("%lld \n",temp);
        n=n-1;
        while(n>1)
        {
            if(temp==n)
            {
                flag=!flag;
                k=k-(1ll<<(temp-1));
                temp=k==1?1:ceil(log(k)/log(2));

            }
            n=temp;

            //printf("%d %d %lld\n",flag,n,k);
        }
        if(k==1)
            printf(flag==1?"Female\n":"Male\n");
        else printf(flag==1?"Male\n":"Female\n");
    }
    return 0;
}
