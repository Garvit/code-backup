#include<stdio.h>
#include<stdbool.h>
#include<string.h>

char *smallwindow(char *p,char *t)
{
    int count[256];
    int i,len=strlen(p),l=strlen(t);
    printf("%d %d \n",len,l);
    bool check[256];
    for(i=0;i<256;i++)
    {
        count[i]=0;
        check[i]=0;
    }

    int num=0,minstart=0,minend=len-1,minlength=len+1,start=0,end=0;
    for(i=0;i<l;i++)
    {
        if(check[t[i]]==0)
        {
            check[t[i]]=1;
            num++;
        }
        count[t[i]]++;
    }
    printf("%d %d\n",num,count['m']);
    for(end=0;end<len;end++)
    {
        if(check[p[end]]==0) continue;

        count[p[end]]--;
        if(count[p[end]]==0) num--;

        if(num>0) continue;

        bool b=check[p[start]];
        while(!b || count[p[start]]<0)
        {
            if(b)
                count[p[start]]++;

            start++;
            b=check[p[start]];
        }
        printf("%d %d\n",start,end);
        if(minlength>(end-start+1))
        {
            minstart=start;
            minend=end;
            minlength=end-start+1;
        }
        num++;
        count[p[start]]++;
        start++;
    }
    char* a;
    a=(char*)calloc(minlength,sizeof(char));
    int k=0;
    for(i=minstart;i<=minend;i++)
    {
        a[k++]=p[i];

    }
    return a;

}
main()
{
    char *p="Looks for minimum string";
    char *t="mums";
    //smallwindow(p,t);
    printf("%s",smallwindow(p,t));
}
