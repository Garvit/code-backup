#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int arr[101];
bool used[101];
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int t,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(!used[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    if(arr[j]==2*arr[i] && !used[j])
                    {
                        ans++;
                        used[j]=true;
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
        memset(arr,0,sizeof(arr));
        memset(used,0,sizeof(used));
    }
}
