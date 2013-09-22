#include<stdio.h>

int inline scan()
{
    int N = 0;
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
int arr[100000];
int main()
{
    int t,at,bt,i,less,more,p,max,maxpeople,n,start;
    t=scan();
    while(t--)
    {
        n=scan();
        bt=scan();
        less=0;more=0;p=0;
        for(i=0;i<n;i++)
        {
            arr[i]=scan();

        }
        for(i=0;i<n;i++)
        {
            less+=arr[i];
            if(less>bt)
            {
                more=less;
                less-=arr[i];
                p=i;
                break;

            }
        }
        if(more==0)
        {
            printf("%d %d\n",less,n);
            continue;
        }
        max=p;
        maxpeople=less;
        start=1;

        while(start < n ){

        if(p>=start)
        {
            more-=arr[start-1];
            if(more>bt)
            {
                less-=arr[start-1];
            }
            else
            {
                less=more;
                more=0;
                for(i=p+1;i<n;i++)
                {
                    less+=arr[i];
                    if(less>bt)
                    {
                        more=less;
                        less-=arr[i];
                        p=i;
                        break;

                    }
                }
                if(more==0)
                {
                    p=n;
                }
                //printf("%d %d %d %d %d\n",start,less,more,max,maxpeople);

                if(max<p-start || (max== p-start && less<maxpeople))
                {
                        max=p-start;
                        maxpeople=less;
                }

                if(i==n)
                {
                    printf("%d %d\n",maxpeople,max);
                    break;
                }
            }
        }
        else
        {
            less=0;more=0;
            for(i=start;i<n;i++)
            {
                less+=arr[i];
                if(less>bt)
                {
                    more=less;
                    less-=arr[i];
                    p=i;
                    break;

                }
            }
            if(more==0)
            {
                p=n;
            }
            //printf("%d %d %d %d %d\n",start,less,more,max,maxpeople);

            if(max<p-start || (max== p-start && less<maxpeople))
            {
                    max=p-start;
                    maxpeople=less;
            }
            if(i==n)
            {
                printf("%d %d\n",maxpeople,max);
                break;
            }

        }
        start++;

        }


    }
    return 0;
}
