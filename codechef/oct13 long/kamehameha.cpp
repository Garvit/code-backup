#include<stdio.h>
#include<map>
#include<utility>
#include<set>
using namespace std;

map<int,set<int> > mapx;
map<int,set<int> > mapy;
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

int main()
{
    int t,n,ans,kills;
    map<int,set<int> >::iterator it,it1;
    set<int>::iterator setit;
    t=scan();
    while(t--)
    {
        ans=0;
        kills=0;
        n=scan();
        int x,y;
        for(int i=0;i<n;i++)
        {
            x=scan();
            y=scan();
            it=mapx.find(x);
            if(it==mapx.end())
            {
                set<int> s;
                s.insert(y);
                mapx.insert(pair<int,set<int> >(x,s));
            }
            else
                it->second.insert(y);

            it=mapy.find(y);
            if(it==mapy.end())
            {
                set<int> s;
                s.insert(x);
                mapy.insert(pair<int,set<int> >(y,s));
            }
            else
                it->second.insert(x);
        }

        while(kills!=n)
        {
            int mx=0,m,umx=0,um;
            set<int> setmx,setumx;
            bool flag=1,flag1=1;
            for(it=mapx.begin();it!=mapx.end();it++)
            {
                if(it->second.size() > umx)
                {
                    umx=it->second.size();
                    um=it->first;
                    setumx=it->second;
                }
                if(it->second.size() > mx)
                {
                    set<int> s=it->second;
                    for(setit=s.begin();setit!=s.end();setit++)
                    {
                        y=*setit;
                        it1=mapy.find(y);
                            if(it1->second.size()==1)
                            {
                                mx=it->second.size();
                                m=it->first;
                                setmx=it->second;
                                //printf("%d %d %d\n",mx,m,it1->first);
                                break;
                            }

                    }
                }
            }
            for(it=mapy.begin();it!=mapy.end();it++)
            {
                if(it->second.size() > umx)
                {
                    umx=it->second.size();
                    um=it->first;
                    setumx=it->second;
                    flag1=0;
                }
                if(it->second.size() > mx)
                {
                    set<int> s=it->second;
                    for(setit=s.begin();setit!=s.end();setit++)
                    {
                        x=*setit;
                        it1=mapx.find(x);
                            if(it1->second.size()==1)
                            {
                                mx=it->second.size();
                                m=it->first;
                                setmx=it->second;
                                flag=0;
                                //printf("%d %d %d\n",mx,m,it1->first);
                                break;
                            }

                    }
                }
            }
            if(mx==0)
            {
                mx=umx;
                m=um;
                setmx=setumx;
                flag=flag1;
            }
            //printf("%d %d\n",mx,m);
            if(flag==1)
            {
                for(setit=setmx.begin();setit!=setmx.end();setit++)
                {
                    y=*setit;
                    kills++;
                    it=mapy.find(y);
                    it->second.erase(m);

                }
                mapx.erase(mapx.find(m));
            }
            else
            {
                for(setit=setmx.begin();setit!=setmx.end();setit++)
                {
                    x=*setit;
                    kills++;
                    it=mapx.find(x);
                    it->second.erase(m);
                }
                mapy.erase(mapy.find(m));
            }
            ans++;
        }
        printf("%d\n",ans);
        mapx.clear();
        mapy.clear();
    }
    return 0;
}
