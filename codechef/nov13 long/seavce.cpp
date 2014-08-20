#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int main()
{
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        vector<int*> v(n);
        int* a=new int[k];
        int ans=-1;
        for(int i=0;i<v.size();i++)
        {
            v[i]=new int[k];
            for(int j=0;j<k;j++)
            {
                scanf("%d",&v[i][j]);
            }
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d",&a[i]);
        }
        int count=0;
        long long mind=LLONG_MAX,diff=0;
        for(vector<int*>::iterator it=v.begin();it!=v.end();)
        {
            int* t=*it;
            int j=0;
            count++;diff=0;
            for(j=0;j<k;j++)
            {
                if(t[j]>a[j])
                {
                    v.erase(it);
                    break;
                }
                diff+=a[j]-t[j];
            }
            if(j==k)
            {
                //cout<<diff<<" "<<mind<<endl;
                if(diff<mind)
                {
                    mind=diff;
                    ans=count;
                }
                it++;
            }
        }
        if(ans!=-1)
            printf("1\n%d\n",ans);
        else    printf("0\n");
        /*for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<k;j++)
            {
                printf("%d ",v[i][j]);
            }
            printf("\n");
        }*/
    }
    return 0;
}
