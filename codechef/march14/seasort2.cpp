#include<stdio.h>
#include<iostream>

using namespace std;

short arr[10000];
short ans[10000][2];
int main()
{
    int n,q=0,l,r;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    l=0;r=n-1;
    int min,max,minp,maxp,t;
    while(l<r)
    {
        min=max=arr[l];
        minp=maxp=l;
        for(int i=l+1;i<=r;i++)
        {
            if(arr[i]<min){ min=arr[i]; minp=i;}
            if(arr[i]>=max){ max=arr[i]; maxp=i; }
        }
        //cout<<min<<" "<<minp<<" "<<max<<" "<<maxp<<endl;
        if(minp==l && maxp==r)
        {
            l++;r--;
        }
        else{
        if(minp==l)
        {
            ans[q][0]=maxp;
            ans[q][1]=r;
            l++;r--;
        }
        else if(maxp==r)
        {
            ans[q][0]=l;
            ans[q][1]=minp;
            l++;r--;
        }
        else
        {
            if(minp-l < r-maxp)
            {
                ans[q][0]=l;
                ans[q][1]=minp;
                l++;
            }
            else
            {
                ans[q][0]=maxp;
                ans[q][1]=r;
                r--;
            }

        }
        for(int i=ans[q][0];i<=(ans[q][1]+ans[q][0])/2;i++)
        {
            t=arr[i];
            arr[i]=arr[ans[q][1]-(i-ans[q][0])];
            arr[ans[q][1]-(i-ans[q][0])]=t;
        }
        q++;
        }
    }
    cout<<q<<endl;
    for(int i=0;i<q;i++)
    {
        cout<<ans[i][0]+1<<" "<<ans[i][1]+1<<endl;
    }
    return 0;
}
