#include<iostream>
#include<stdio.h>
#include<string.h>
#include<set>

using namespace std;
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
set<int> str1[51];
set<int> str2[51];

bool ch[51];
char *eval(int i,char *k1,char *k2,int m,int l,bool check[51])
{
    if(i>=m) return k1;
    int flag=0,p=0;
    char *ans=new char[m*l];
    ans[0]='\0';
    int size=str1[i].size();
    for(set<int>::iterator it=str1[i].begin();it!=str1[i].end() && p<size;it++,p++)
    {
        char *t1=k1;
        char *t2=k2;
        int z=*it; if(check[z]==1) continue;
        for(int j=0;j<l;j++)
        {
            flag=1;
            if(t1[i*l+j]=='?' && t2[z*l+j]!='?')
            {
                t1[i*l+j]=t2[z*l+j];
            }
            else if(t1[i*l+j]!='?' && t2[z*l+j]=='?')
            {
                t2[z*l+j]=t1[i*l+j];
            }
            else if(t1[i*l+j]=='?' && t2[z*l+j]=='?')
            {
                t2[z*l+j]=t1[i*l+j]='a';
            }
        }
        check[z]=1;
        printf("%s\n",t2);
        //char *val=eval(i+1,t1,t2,m,l,check);
        /*if(strlen(ans)==0) ans=val;
        else
        {
            if(strlen(val)!=0 && strcmp(val,ans)<0)
            {
                ans=val;
            }
        }*/
        check[z]=0;
    }
    return ans;

}
int main()
{
	int t,m,z,len,l,flag,i,j,k,f;
	char k1[120],k2[120];
	t=scan();
	for(z=1;z<=t;z++)
	{
		m=scan();
		scanf("%s",k1);
		scanf("%s",k2);
		len=strlen(k1);
		l=len/m;
		for(i=0;i<m;i++)
		{
			flag=0;
			for(j=0;j<m;j++)
			{
				for(k=0;k<l;k++)
				{
					if(k1[i*l+k]!='?' && k2[j*l+k]!='?' && k1[i*l+k]!=k2[j*l+k]) break;
				}
				if(k==l)
				{
					str1[i].insert(j);
					flag=1;
				}
			}
			if(flag==0)
			{
				printf("Case #%d: IMPOSSIBLE\n",z);
				break;
			}
		}
		if(i==m)
		{

			for(i=0;i<m;i++)
			{
				if(str1[i].size()==1)
				{
					set<int>::iterator it=str1[i].begin();
					int elem=*it;
					for(j=0;j<m;j++)
					{
						if(j!=i)
						{
						  str1[j].erase(elem);
						  if(str1[j].size()==0) break;
						}
					}
					if(j!=m)
					{
						printf("Case #%d: IMPOSSIBLE\n",z);
						break;
					}
				}
			}

			if(i==m)
			{
				char *ans=eval(0,k1,k2,m,l,ch);
				if(strlen(ans)==0) printf("Case #%d: IMPOSSIBLE\n",z);
				else printf("Case #%d: %s\n",z,ans);
				for(i=0;i<m;i++)
				{
					for(set<int>::iterator it=str1[i].begin();it!=str1[i].end();it++)
					{
					  printf("%d ",*it);
					}
					printf("\n");
				}
			}

		}
		for(i=0;i<m;i++)
		{
			str1[i].clear();
		}
	}
}
