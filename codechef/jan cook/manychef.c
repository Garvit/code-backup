#include<stdio.h>
#include<string.h>

int main()
{
    int t,l,i,cont=0,flag=0,j,temp,k;
    char s[2020];
    char ans[2020];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]!='?')
            {
                ans[i]=s[i];
                if(s[i]=='C')
                    flag=1;
                else if(s[i]=='H' && flag==1)
                    flag=2;
                else if(s[i]=='E' && flag==2)
                    flag=3;
                else
                    flag=0;
            }
            else
            {
                cont=1;
                for(j=i+1;j<l;j++)
                {
                    if(s[j]=='?')
                        cont++;
                    else
                        break;
                }
                if(j+2<l && s[j]=='H' && (s[j+1]=='E' || s[j+1]=='?') && (s[j+2]=='F' || s[j+2]=='?' ))
                {
                    ans[j-1]='C';
                    cont--;
                    temp=cont/4;
                    for(k=1;k<=temp;k++)
                    {
                        ans[j-1-k*4]='C';
                        ans[j-1-k*4+1]='H';
                        ans[j-1-k*4+2]='E';
                        ans[j-1-k*4+3]='F';
                    }
                    cont=cont-temp*4;
                    for(k=0;k<cont;k++)
                    {
                        ans[i+k]='A';
                    }

                    ans[j]='H';
                    ans[j+1]='E';
                    ans[j+2]='F';
                    cont=0;
                    flag=0;
                    i=j+3-1;
                }
                else if(cont>=2 && j+1<l && s[j]=='E' && (s[j+1]=='F' || s[j+1]=='?' ))
                {
                    ans[j-1]='H';
                    ans[j-2]='C';
                    cont-=2;
                    temp=cont/4;
                    for(k=1;k<=temp;k++)
                    {
                        ans[j-2-k*4]='C';
                        ans[j-2-k*4+1]='H';
                        ans[j-2-k*4+2]='E';
                        ans[j-2-k*4+3]='F';
                    }
                    cont=cont-temp*4;
                    for(k=0;k<cont;k++)
                    {
                        ans[i+k]='A';
                    }

                    ans[j]='E';
                    ans[j+1]='F';
                    cont=0;
                    flag=0;
                    i=j+2-1;
                }
                else if(cont>=3 && j<l && s[j]=='F')
                {
                    ans[j-1]='E';
                    ans[j-2]='H';
                    ans[j-3]='C';
                    cont-=3;
                    temp=cont/4;
                    for(k=1;k<=temp;k++)
                    {
                        ans[j-3-k*4]='C';
                        ans[j-3-k*4+1]='H';
                        ans[j-3-k*4+2]='E';
                        ans[j-3-k*4+3]='F';
                    }
                    cont=cont-temp*4;
                    for(k=0;k<cont;k++)
                    {
                        ans[i+k]='A';
                    }
                    ans[j]='F';
                    cont=0;
                    flag=0;
                    i=j+1-1;
                }
                else if(flag+cont>=4)
                {

                     if(flag==1)
                     {
                         ans[i]='H';
                         ans[i+1]='E';
                         ans[i+2]='F';
                         cont-=3;
                     }
                     else if(flag==2)
                     {
                         ans[i]='E';
                         ans[i+1]='F';
                         cont-=2;
                     }
                     else if(flag==3)
                     {
                         ans[i]='F';
                         cont--;
                     }
                     else
                     {
                        temp=cont/4;
                        for(k=1;k<=temp;k++)
                        {
                            ans[j-k*4]='C';
                            ans[j-k*4+1]='H';
                            ans[j-k*4+2]='E';
                            ans[j-k*4+3]='F';
                        }
                        cont=cont-temp*4;
                        for(k=0;k<cont;k++)
                        {
                            ans[i+k]='A';
                        }

                     }
                     cont=0;flag=0;
                     i=j-1;
                }
                else
                {
                    for(k=0;k<cont;k++)
                    {
                        ans[i+k]='A';
                    }
                    i=j-1;
                    flag=0;cont=0;
                }

            }

        }
        ans[l]='\0';
        printf("%s\n",ans);
        memset(ans,0,sizeof(ans));

    }
    return 0;
}
