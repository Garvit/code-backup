#include<iostream>
#include<deque>
#include<cstring>
#include<cmath>
using namespace std;

int skill[500000];
int cheflimit[1000];
int cand[500000]={0};
int main()
{
    deque<int> maxwindow;
    deque<int> minwindow;
    int n,limit,i,t,m,c,q,a,b,d,max,min,temp;
    temp=pow(2,30);
    cin>>t;
    while(t--){
        memset(cand,0,sizeof(cand));
        memset(skill,0,sizeof(skill));
        memset(cheflimit,0,sizeof(cheflimit));

    cin>>n>>c>>q>>a>>b>>d;
    limit=n<=10000?n:10000;
    for(i=0;i<limit;i++)
    {
        cin>>skill[i];
    }
    if(n>10000)
    {
        for(i=10000;i<n;i++)
        {
            skill[i]=(a*skill[i-1]+b*skill[i-2]+d)%(temp);
        }
    }
    for(i=0;i<q;i++)
    {
        cin>>cheflimit[i];

    }
    cand[0]=n;
    for(i=0;i<n-1;i++)
    {
        min=skill[i]<=skill[i+1]?skill[i]:skill[i+1];
        max=skill[i]>skill[i+1]?skill[i]:skill[i+1];
        if(max-min>c)
        {
            continue;
        }
        else
        {
            cand[1]++;
            for(int j=i+2;j<n;j++)
            {
                max=max>skill[j]?max:skill[j];
                min=min<=skill[j]?min:skill[j];
                if(max-min>c)
                {
                    break;
                }
                else
                {
                    cand[j-i]++;
                }

            }
        }
    }
    for(i=0;i<q;i++)
    {

    for(int j=0;j<n;j++)
    {
        if(cand[j]<=cheflimit[i])
        {
            cout<<j+1<<" "<<cand[j]<<endl;
            break;
        }
    }
    }

    }
    return 0;
}
