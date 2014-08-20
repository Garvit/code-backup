#include<stdio.h>

int main()
{
    int t,d;
    double a1,a2;
    char t1[10],t2[10];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",t1);
        scanf("%s",t2);
        scanf("%d",&d);
        int h1,h2,m1,m2;
        h1=(t1[0]-48)*10+(t1[1]-48);
        h2=(t2[0]-48)*10+(t2[1]-48);
        m1=(t1[3]-48)*10+(t1[4]-48);
        m2=(t2[3]-48)*10+(t2[4]-48);
        a1=(h1*60+m1)-(h2*60+m2)+d;
        a2=(h1*60+m1)-(h2*60+m2);
        if(2*d > a2) a2=a2/2+d;
        printf("%.1lf ",a1);
        printf("%.1lf\n",a2);
    }
    return 0;
}
