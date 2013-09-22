#include<stdio.h>
#include<string.h>
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N;
}

int main()
{
    int t,i,j,count[2][5]={0};
    int ls=0,lf=0,temp,k,l;
    t=scan();
    char a[20010];
    char b[20010];
    for(i=0;i<t;i++)
    {
        for(k=0;k<2;k++)
        {
            for(l=0;l<5;l++)
            {
                count[k][l]=0;
            }
        }
        ls=0;lf=0;
        char c;
        j=0;
        c=getchar_unlocked();
        while(c!='\n')
        {
            a[j++]=c;
            c=getchar_unlocked();
        }
        a[j]='\0';
        j=0;
        c=getchar_unlocked();
        while(c!='\n')
        {
            b[j++]=c;
            c=getchar_unlocked();
        }
        b[j]='\0';
        //printf("%c",a[0]);
        for(j=0;j<strlen(a);j++)
        {
            if(a[j]>'7')
                count[0][0]++;
            else if(a[j]=='7')
                count[0][1]++;
            else if(a[j]<'7' && a[j]>'4')
                count[0][2]++;
            else if(a[j]=='4')
                count[0][3]++;
            else if(a[j]<'4' && a[j]>='0')
                count[0][4]++;

            if(b[j]>'7')
                count[1][0]++;
            else if(b[j]=='7')
                count[1][1]++;
            else if(b[j]<'7' && b[j]>'4')
                count[1][2]++;
            else if(b[j]=='4')
                count[1][3]++;
            else if(b[j]<'4' && b[j]>='0')
                count[1][4]++;

        }

        //-----------------------------
        int p1[5]={0,2,4,3,1};
        for(j=0;j<5;j++)
        {
            if(count[0][0]<=count[1][p1[j]])
            {
                temp=count[0][0];
                count[0][0]=0;
                count[1][p1[j]]-=temp;
                break;
            }
            else
            {
                temp=count[1][p1[j]];
                count[1][p1[j]]=0;
                count[0][0]-=temp;
            }
        }
        for(j=0;j<5;j++)
        {
            if(count[1][0]<=count[0][p1[j]])
            {
                temp=count[1][0];
                count[1][0]=0;
                count[0][p1[j]]-=temp;
                break;
            }
            else
            {
                temp=count[0][p1[j]];
                count[0][p1[j]]=0;
                count[1][0]-=temp;
            }
        }

        //-----------------------------

        int p2[4]={2,4,3,1};
        for(j=0;j<4;j++)
        {
            if(count[0][1]<=count[1][p2[j]])
            {
                temp=count[0][1];
                count[0][1]=0;
                count[1][p2[j]]-=temp;
                ls+=temp;
                break;
            }
            else
            {
                temp=count[1][p2[j]];
                count[1][p2[j]]=0;
                count[0][1]-=temp;
                ls+=temp;
            }
        }
        for(j=0;j<4;j++)
        {
            if(count[1][1]<=count[0][p2[j]])
            {
                temp=count[1][1];
                count[1][1]=0;
                count[0][p2[j]]-=temp;
                ls+=temp;
                break;
            }
            else
            {
                temp=count[0][p2[j]];
                count[0][p2[j]]=0;
                count[1][1]-=temp;
                ls+=temp;
            }
        }

        //-------------------------------

        int p3[3]={2,4,3};
        for(j=0;j<3;j++)
        {
            if(count[0][2]<=count[1][p3[j]])
            {
                temp=count[0][2];
                count[0][2]=0;
                count[1][p3[j]]-=temp;

                break;
            }
            else
            {
                temp=count[1][p3[j]];
                count[1][p3[j]]=0;
                count[0][2]-=temp;

            }
        }
        for(j=0;j<4;j++)
        {
            if(count[1][2]<=count[0][p3[j]])
            {
                temp=count[1][2];
                count[1][2]=0;
                count[0][p3[j]]-=temp;

                break;
            }
            else
            {
                temp=count[0][p3[j]];
                count[0][p3[j]]=0;
                count[1][2]-=temp;

            }
        }

        //-------------------------------
        int p4[2]={4,3};
        for(j=0;j<2;j++)
        {
            if(count[0][3]<=count[1][p4[j]])
            {
                temp=count[0][3];
                count[0][3]=0;
                count[1][p4[j]]-=temp;
                lf+=temp;
                break;
            }
            else
            {
                temp=count[1][p4[j]];
                count[1][p4[j]]=0;
                count[0][3]-=temp;
                lf+=temp;
            }
        }
        for(j=0;j<2;j++)
        {
            if(count[1][3]<=count[0][p4[j]])
            {
                temp=count[1][3];
                count[1][3]=0;
                count[0][p4[j]]-=temp;
                lf+=temp;
                break;
            }
            else
            {
                temp=count[0][p4[j]];
                count[0][p4[j]]=0;
                count[1][3]-=temp;
                lf+=temp;
            }
        }

        //-------------------------------

        for(j=0;j<ls;j++)
            putchar('7');
        for(j=0;j<lf;j++)
            putchar('4');

        putchar('\n');
    }
    return 0;
}

