#include <stdio.h>
#include <vector>

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
vector<int> zfunction(vector<int>& str)
{
    int n=str.size();
    vector<int> z(n);
    int l=0,r=0;
    for(int i=1;i<n;++i)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && str[i+z[i]]==str[z[i]])
            ++z[i];
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

void countMatches(vector<int>& adiff, vector<int>& bdiff)
{
    vector<int> str=bdiff;
    str.insert(str.end(),adiff.begin(),adiff.end());
    vector<int> zfunc=zfunction(str);
    int ans=0;
    for(int i=bdiff.size();i<zfunc.size();++i)
    {
        if(zfunc[i]>=bdiff.size()) ++ans;
    }
    printf("%d",ans);
}
int main()
{
    int n,w;
    n=scan();
    w=scan();
    vector<int> a(n);
    vector<int> b(w);
    for(int i=0;i<n;++i)
        a[i]=scan();
    for(int i=0;i<w;++i)
        b[i]=scan();

    if(w==1)
    {
        printf("%d",n);
        return 0;
    }
    vector<int> adiff(n-1);
    vector<int> bdiff(w-1);
    for(int i=0;i<n-1;++i)
    {
        adiff[i]=a[i+1]-a[i];
    }
    for(int i=0;i<w-1;++i)
    {
        bdiff[i]=b[i+1]-b[i];
    }
    countMatches(adiff,bdiff);
    return 0;
}

