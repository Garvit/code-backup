#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool arr[10];
int count[10];
int num[300];
int main()
{
    char str[300];
    int mul[]={1,3,2,6,4,5};
    while(scanf("%s",str)!=EOF){
    int l=strlen(str),i,sum=0;
    for(i=0;i<l;i++){
        //printf("%d ",str[i]);
        num[i]=str[i]-'0';
        //printf("%d ",num[i]);
        sum+=num[i];
        count[num[i]]++;
    }
    //printf("ok");
    arr[1]=1;
    if((num[l-1])%2==0)
    {
        arr[2]=1;
    }
    if(sum%3==0) arr[3]=1;
    if(sum%9==0) arr[9]=1;
    if(arr[2]==1 && arr[3]==1) arr[6]=1;
    if(num[l-1]==0 || num[l-1]==5) arr[5]=1;
    if(l>=2)
    {
        int t=num[l-2]*10+num[l-1];
        if(t%4==0) arr[4]=1;
    }
    if(l>=3)
    {
        int t=num[l-3]*100+num[l-2]*10+num[l-1];
        if(t%8==0) arr[8]=1;

    }
    int sum1=0,ans=0;
    for(i=0;i<l;i++)
    {
        sum1+=num[l-1-i]*mul[i%6];
    }
    if(sum1%7==0)
        arr[7]=1;

    for(i=1;i<10;i++)
    {
        ans+=count[i]*arr[i];
    }
    printf("%d\n",ans);
    memset(count,0,sizeof(count));
    memset(arr,0,sizeof(arr));
    }
}
