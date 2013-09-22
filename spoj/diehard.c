#include<stdio.h>
#include<string.h>
int mem[1100][1100];
int fire(int h,int a);
int water(int h,int a)
{
    if(mem[h][a]) return mem[h][a];
    if(h-5<=0 || a-10<=0)
        return 0;
    //h-=2;a-=8;
    int time=2;
    int c1=water(h-2,a-8);
    int c2=fire(h-2,a-8);
    time+=(c1>c2)?c1:c2;
    mem[h][a]=time;
    return mem[h][a];

}
int fire(int h,int a)
{
    if(mem[h][a]) return mem[h][a];
    if(h-20<=0)
        return 0;
    //h-=17;a+=7;
    int time=2;
    int c1=water(h-17,a+7);
    int c2=fire(h-17,a+7);
    time+=(c1>c2)?c1:c2;
    mem[h][a]=time;
    return mem[h][a];
}

int main()
{
    int t,h,a,time,c1,c2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&a);
        h+=3;a+=2;
        time=1;
        c1=water(h,a);
        c2=fire(h,a);
        time+=(c1>c2)?c1:c2;
        printf("%d\n",time);
        memset(mem,0,sizeof(mem));
    }
    return 0;
}
