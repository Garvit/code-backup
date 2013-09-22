#include<stdio.h>
#include<string.h>

char str[20010];


int front(int n,int k)
{
    int i,count=0,temp=1,flag=0;
    for(i=0;i<n-1;i++)
        {
            if(str[i]==str[i+1])
                temp++;
            else
            {
                if(temp>=k)
                    flag=1;
                count+=temp/k+(temp%k!=0);
                temp=1;
            }
        }
        if(temp>=k)
                flag=1;
        count+=temp/k+(temp%k!=0);
        if(flag==0)
            return -1;
        else
            return count;
}


int main()
{
    int t,n,k,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        scanf("%s",str);
        printf("%d\n",front(n,k));

    }
    return 0;
}
