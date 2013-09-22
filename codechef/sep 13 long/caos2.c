#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int left[500][500];
int right[500][500];
int top[500][500];
int bottom[500][500];
char arr[500][500];
int numprimes[510];
bool pr[510];
int min(int a,int b)
{
    return a<b?a:b;
}
void seive()
{
    int i,j;
    numprimes[1]=0;
    for(i=2;i<=500;i++)
    {
        numprimes[i]=numprimes[i-1];
        if(pr[i]==0){
            numprimes[i]++;
        for(j=i;j<=500;j+=i)
        {
            pr[j]=1;
        }
        }
    }
}
int main()
{
    int t,r,c,i,ans=0,j;
    seive();
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%s",arr[i]);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                top[i][j]=((i!=0) && arr[i-1][j]=='^')?(top[i-1][j]+1):0;
                left[i][j]=( (j!=0) && arr[i][j-1]=='^')?(left[i][j-1]+1):0;
            }
        }
        for(i=r-1;i>=0;i--)
        {
            for(j=c-1;j>=0;j--)
            {
                bottom[i][j]=((i<r-1) && arr[i+1][j]=='^')?(bottom[i+1][j]+1):0;
                right[i][j]=( (j<c-1) && arr[i][j+1]=='^')?(right[i][j+1]+1):0;
            }
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(arr[i][j]!='#')
                {
                    int value=min(min(left[i][j],right[i][j]),min(top[i][j],bottom[i][j]));
                    //printf("%d\n",value);
                    ans+=numprimes[value];
                }
            }
        }
        printf("%d\n",ans);
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        memset(top,0,sizeof(top));
        memset(bottom,0,sizeof(bottom));
    }
    return 0;
}
