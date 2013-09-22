#include<iostream>
#include<deque>
#include<cstring>
#include<cmath>
using namespace std;

int skill[500000];
int cheflimit[1000];
int cand[500000]={0};
int ans[1000];
int main()
{
    deque<int> maxwindow;
    deque<int> minwindow;
    int n,limit,w=3,i,t,m,c,q,a,b,d,max,min,temp,flag,mincheflimit=500000;
    temp=pow(2,30);
    cin>>t;
    while(t--){
        memset(cand,0,sizeof(cand));
        memset(skill,0,sizeof(skill));
        memset(cheflimit,0,sizeof(cheflimit));
        memset(ans,0,sizeof(ans));
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
        if(cheflimit[i]<mincheflimit)
            mincheflimit=cheflimit[i];
    }
    cand[0]=n;
    w=2;
    while(w<=n){

    for (i = 0; i < w; i++) {
    while (!maxwindow.empty() && skill[i] >= skill[maxwindow.back()])
      maxwindow.pop_back();
    maxwindow.push_back(i);

    while (!minwindow.empty() && skill[i] <= skill[minwindow.back()])
      minwindow.pop_back();
    minwindow.push_back(i);
  }
  for(i=w;i<n;i++)
  {
      max=skill[maxwindow.front()];
      min=skill[minwindow.front()];
      if((max-min)<=c)
      {
          cand[w-1]++;
      }

      while (!maxwindow.empty() && skill[i] >= skill[maxwindow.back()])
      maxwindow.pop_back();
      while (!maxwindow.empty() && maxwindow.front() <= i-w)
      maxwindow.pop_front();
      maxwindow.push_back(i);



      while (!minwindow.empty() && skill[i] <= skill[minwindow.back()])
      minwindow.pop_back();
      while (!minwindow.empty() && minwindow.front() <= i-w)
      minwindow.pop_front();
      minwindow.push_back(i);
  }
 max=skill[maxwindow.front()];
      min=skill[minwindow.front()];
      if((max-min)<=c)
      {
          cand[w-1]++;
      }
  maxwindow.clear();
  minwindow.clear();
  if(cand[w-1]<=mincheflimit)
            break;
  //---------------

  w++;
    }
for(i=0;i<n;i++)
    {
        cout<<cand[i]<<endl;
    }
for(i=0;i<q;i++)
{
    flag=0;
    for(int j=0;j<w;j++)
    {
        if(cand[j]<=cheflimit[i] && (flag==0 || cand[j]>cand[ans[i]]))
        {
            flag=1;
            ans[i]=j;
        }
    }
    cout<<ans[i]+1<<" "<<cand[ans[i]]<<endl;
}
  /*for(i=0;i<=n-w;i++)
  {
      cout<<"min= "<<MIN[i]<<endl;
      cout<<"max= "<<MAX[i]<<endl;
  }*/
    }
    return 0;
}
