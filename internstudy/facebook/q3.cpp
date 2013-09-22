#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int arr[6][6];
int output[6][6];
int n,m,numOfImp=0,usednum=0;
bool used[50];
vector<int> unused;
int count(int i,int j)
{
    int max=0,maxi=0,maxj=0;
    if(i>0 && arr[i-1][j]>max)
    {
        max=arr[i-1][j];
        maxi=i-1;
        maxj=j;
    }
    if(j>0 && arr[i][j-1]>max)
    {
        max=arr[i][j-1];
        maxi=i;
        maxj=j-1;
    }
    if(j<m-1 && arr[i][j+1]>max)
    {
        max=arr[i][j+1];
        maxi=i;
        maxj=j+1;
    }
    if(i<n-1 && arr[i+1][j]>max)
    {
        max=arr[i+1][j];
        maxi=i+1;
        maxj=j;
    }
    if(max>arr[i][j])
    {
        return 1+count(maxi,maxj);
    }
    else
        return 1;

}
void print(int a[][6])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool check(int a[][6],int b[][6])
{
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]!=b[i][j])
                {
                    if(a[i][j]<b[i][j]) return true;
                    else return false;
                }
            }
        }
        return true;
}
void process()
{
    int num=count(0,0);
    //print(arr);
    //cout<<num<<endl;
    if(num>numOfImp)
    {
        numOfImp=num;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                output[i][j]=arr[i][j];
            }
        }
    }
    else if(num==numOfImp)
    {
        if(check(arr,output))
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    output[i][j]=arr[i][j];
                }
            }
        }
    }
}
void backtrack(int p)
{
    if(usednum==n*m)
    {
        process();
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==-1){
                /*for(int k=1;k<=n*m;k++)
                {
                    if(used[k]==false)
                    {
                        arr[i][j]=k;
                        used[k]=true;
                        usednum++;

                        //cout<<"calling backtrack k "<<k<<endl;
                        backtrack();

                        usednum--;
                        used[k]=false;
                        arr[i][j]=-1;

                    }

                }*/
                for(int k=p;k<unused.size();k++)
                {
                    int temp=unused[k];
                    unused[k]=unused[p];
                    unused[p]=temp;

                    arr[i][j]=unused[p];
                    usednum++;

                    backtrack(p+1);

                    usednum--;
                    arr[i][j]=-1;

                    temp=unused[k];
                    unused[k]=unused[p];
                    unused[p]=temp;
                }
                return;
            }
        }
    }

}
int main()
{
    cin>>n>>m;
    char c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int r=scanf("%d",&arr[i][j]);
            if(r<=0){
                cin>>c;
                arr[i][j]=-1;
            }
            else{
                usednum++;
                used[arr[i][j]]=true;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(!used[i])
            unused.push_back(i);
    }
    //print(arr);
    //cout<<count(0,0);
    backtrack(0);
    cout<<numOfImp<<endl;
    print(output);

}
