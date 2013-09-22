#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<cstdlib>
using namespace std;
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
int diff[20000];
int sec[20000];
int main()
{
    int t,i,n,j;
    char str[10];
    char *p;
    t=scan();
    while(t--)
    {
        n=scan();
        for(j=0;j<n;j++)
        {
            scanf("%s",str);
            p=strtok(str,":");
            sec[j]=atoi(p)*3600;
            p=strtok(NULL,":");
            sec[j]+=atoi(p)*60;
            p=strtok(NULL,":");
            sec[j]+=atoi(p);

        }
        sort(sec,sec+n);
        int max=0;
    }
    return 0;
}
