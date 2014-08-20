#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool pr[10000000];
int primes[1000000];
int cp=0;
void sieve()
{
    int limit=ceil(sqrt(10000000)),start,i;
    for(start=3;start<10000000;start+=2)
    {
        if(pr[start]==0){
            primes[cp++]=start;
        if(start<limit){
        for(i=start*start;i<10000000;i+=(2*start))
        {
            pr[i]=1;
        }}
        }
    }
}
int reverse(int n)
{
    int d,rev=0;
    while(n>0)
    {
        d=n%10;
        rev=rev*10+d;
        n/=10;
    }
    return rev;
}
int func(int n)
{
    int d[4]={1,3,7,9};
    int i1,i2,i3,i4,i5,i6,i7,num,r,count=0;
    if(n==2)
    {
        for(i1=0;i1<4;i1++)
        {
            for(i2=0;i2<4;i2++)
            {
                num=d[i1]*10+d[i2];
                r=reverse(num);
                if(pr[num]==0 && r!=num && pr[r]==0)
                {
                    count++;
                    pr[r]=1;
                }
            }
        }
    }
    else if(n==3)
    {
        for(i1=0;i1<4;i1++)
        {
            for(i3=0;i3<=9;i3++)
            {
                for(i2=0;i2<4;i2++)
                {
                    num=d[i1]*100+i3*10+d[i2];
                    r=reverse(num);
                    if(pr[num]==0 && r!=num && pr[r]==0)
                    {
                        count++;
                        pr[r]=1;
                    }
                }
            }
        }
    }
    else if(n==4)
    {
        for(i1=0;i1<4;i1++)
        {
            for(i3=0;i3<=9;i3++)
            {
                for(i4=0;i4<=9;i4++){
                    for(i2=0;i2<4;i2++)
                    {
                        num=d[i1]*1000+i3*100+i4*10+d[i2];
                        r=reverse(num);
                        if(pr[num]==0 && r!=num && pr[r]==0)
                        {
                            count++;
                            pr[r]=1;
                        }
                    }
                }
            }
        }
    }
    else if(n==5)
    {
        for(i1=0;i1<4;i1++)
        {
            for(i3=0;i3<=9;i3++)
            {
                for(i4=0;i4<=9;i4++)
                {
                    for(i5=0;i5<=9;i5++)
                    {
                        for(i2=0;i2<4;i2++)
                        {
                            num=d[i1]*10000+i3*1000+i4*100+i5*10+d[i2];
                            r=reverse(num);
                            if(pr[num]==0 && r!=num && pr[r]==0)
                            {
                                count++;
                                pr[r]=1;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==6)
    {
        for(i1=0;i1<4;i1++)
        {
            for(i3=0;i3<=9;i3++)
            {
                for(i4=0;i4<=9;i4++)
                {
                    for(i5=0;i5<=9;i5++)
                    {
                        for(i6=0;i6<=9;i6++){
                            for(i2=0;i2<4;i2++)
                            {
                                num=d[i1]*100000+i3*10000+i4*1000+i5*100+i6*10+d[i2];
                                r=reverse(num);
                                if(pr[num]==0 && r!=num && pr[r]==0)
                                {
                                    count++;
                                    pr[r]=1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==7)
    {
        for(i1=0;i1<4;i1++)
        {
            for(i3=0;i3<=9;i3++)
            {
                for(i4=0;i4<=9;i4++)
                {
                    for(i5=0;i5<=9;i5++)
                    {
                        for(i6=0;i6<=9;i6++)
                        {
                            for(i7=0;i7<=9;i7++){
                                for(i2=0;i2<4;i2++)
                                {
                                    num=d[i1]*1000000+i3*100000+i4*10000+i5*1000+i6*100+i7*10+d[i2];
                                    r=reverse(num);
                                    if(pr[num]==0 && r!=num && pr[r]==0)
                                    {
                                        count++;
                                        pr[r]=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return count;
}
int main()
{
    sieve();
    int count=0,i,r,p;
    printf("%d\n",cp);
    for(i=0;i<cp;i++)
    {
        p=primes[i];
        r=reverse(p);
        if(r!=p && r%2==1 && pr[r]==0){
        //printf("%d\n",i);
        count++;
        pr[p]=1;
        }

    }

    /*count+=func(2);
    count+=func(3);
    count+=func(4);
    count+=func(5);
    count+=func(6);
    count+=func(7);*/
    printf("%d",count);
    return 0;
}
