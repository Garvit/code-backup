#include<stdio.h>
#include<map>
#include<utility>

using namespace std;

int dem[1000][2];
bool killed[1000];
map<int,int> mapx;
map<int,int> mapy;
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
    map<int,int>::iterator it,it1;
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
            dem[i][0]=x;
            dem[i][1]=y;
            killed[i]=0;
            it=mapx.find(x);
            if(it==mapx.end())
            {
                mapx.insert(pair<int,int>(x,1));
            }
            else
                it->second++;

            it=mapy.find(y);
            if(it==mapy.end())
            {
                mapy.insert(pair<int,int>(y,1));
            }
            else
                it->second++;
        }
        while(kills!=n)
        {
            int mx=0,m,umx=0,um;
            bool flag=1,flag1=1;
            for(it=mapx.begin();it!=mapx.end();it++)
            {
                if(it->second > umx)
                {
                    umx=it->second;
                    um=it->first;
                }
                if(it->second > mx)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(killed[i]==0 && dem[i][0]==it->first)
                        {
                            it1=mapy.find(dem[i][1]);
                            if(it1->second==1)
                            {
                                mx=it->second;
                                m=it->first;
                                //printf("%d %d %d\n",mx,m,it1->first);
                                break;
                            }
                        }
                    }
                }
            }
            for(it=mapy.begin();it!=mapy.end();it++)
            {
                if(it->second > umx)
                {
                    umx=it->second;
                    um=it->first;
                    flag1=0;
                }
                if(it->second > mx)
                {
                    for(int i=0;i<n;i++)
                    {
                        if(killed[i]==0 && dem[i][1]==it->first)
                        {
                            it1=mapx.find(dem[i][0]);
                            if(it1->second==1)
                            {
                                mx=it->second;
                                m=it->first;
                                flag=0;
                                //printf("%d %d%d\n",mx,m,it1->first);
                                break;
                            }
                        }
                    }
                }
            }
            if(mx==0)
            {
                mx=umx;
                m=um;
                flag=flag1;
            }
            //printf("%d %d\n",mx,m);
            if(flag==1)
            {
                for(int i=0;i<n;i++)
                {
                    if(killed[i]==0 && dem[i][0]==m){
                        killed[i]=1;
                        kills++;
                        it=mapy.find(dem[i][1]);
                        it->second--;
                    }
                }
                mapx.erase(mapx.find(m));
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(killed[i]==0 && dem[i][1]==m){
                        killed[i]=1;
                        kills++;
                        it=mapx.find(dem[i][0]);
                        it->second--;
                    }
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
