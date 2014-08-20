#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

void computePrefix(char *pat,int *lps)
{
    int m=strlen(pat);
    lps[0]=0;
    int k=0;
    for(int q=1;q<m;q++)
    {
        while(k>0 && pat[q]!=pat[k])
            k=lps[k-1];
        if(pat[k]==pat[q])
            k++;
        lps[q]=k;
        cout<<lps[q]<<endl;
    }
}
void KMP(char *txt,char *pat)
{
    int n=strlen(txt);
    int m=strlen(pat);
    int *lps=new int(m);
    computePrefix(pat,lps);
    int q=0;
    for(int i=0;i<n;i++)
    {
        while(q>0 && pat[q]!=txt[i])
            q=lps[q-1];
        if(pat[q]==txt[i])
            q++;
        if(q==m)
        {
            cout<<"pattern found at index "<<i-m+1<<endl;
            q=lps[q-1];
        }
    }
}
int main()
{
    char *txt="abababac";
    char *pat="abab";
    KMP(txt,pat);
    return 0;
}
