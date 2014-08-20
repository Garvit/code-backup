#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int exs[26];
int freq[26];
int main()
{
    int t,k,i;
    char fs[30],ct[150010];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",fs);
        getchar();
        char c;
        k=0;
        while((c=getchar())!='\n')
        {
            ct[k++]=c;
            if(c>='a' && c<='z') freq[c-'a']++;
            else if(c>='A' && c<='Z') freq[c-'A']++;
        }
        pair<int,char> temparr[26];
        for(i=0;i<26;i++)
        {
            temparr[i]=make_pair(freq[i],'a'+i);
        }
        sort(temparr,temparr+26);
        for(i=0;i<26;i++)
        {
            exs[temparr[i].second-'a']=i;
        }
        for(i=0;i<k;i++)
        {
            if(ct[i]>='a' && ct[i]<='z') putchar(fs[exs[ct[i]-'a']]);
            else if(ct[i]>='A' && ct[i]<='Z') putchar(fs[exs[ct[i]-'A']]-32);
            else putchar(ct[i]);
        }
        putchar('\n');
        memset(freq,0,sizeof(freq));
        memset(exs,0,sizeof(exs));
    }
    return 0;
}
