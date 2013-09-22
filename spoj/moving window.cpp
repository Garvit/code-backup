#include<stdio.h>
#include<iostream>
#include<deque>
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
deque<int> slide;
int arr[1000000];
int main()
{
    int n,k,z;
    n=scan();
    for(int i=0;i<n;i++)
    {
        arr[i]=scan();
    }
    k=scan();
    slide.push_back(0);
    //printf("%d ",slide.size());
    int it;

    //printf("%d \n",slide.back());
    for(int i=1;i<k;i++)
    {
        it=slide.back();
        //printf("%d ",*it);
        if(arr[i]<arr[it])
        {
            slide.push_back(i);
        }
        else
        {
            while(!slide.empty())
            {
                it=slide.back();
                if(arr[i]>=arr[it])
                    slide.pop_back();
                else
                {
                    break;
                }
            }
            slide.push_back(i);
        }
    }
    printf("%d ",arr[slide[0]]);
    if(slide[0]==0) slide.pop_front();
    for(int i=k;i<n;i++)
    {
        it=slide.back();
        if(arr[i]<arr[it])
        {
            slide.push_back(i);
        }
        else
        {
            while(!slide.empty())
            {
                it=slide.back();
                if(arr[i]>=arr[it])
                    slide.pop_back();
                else
                {
                    break;
                }
            }
            slide.push_back(i);
        }
        printf("%d ",arr[slide[0]]);
        if(slide[0]==i-k+1) slide.pop_front();
    }
    return 0;
}
