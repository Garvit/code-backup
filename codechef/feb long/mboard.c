#include<stdio.h>
#include<string.h>
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
int row[500000];
int col[500000];
int allr[500000];
int allc[500000];
int temp[500000];
int notsetrow[500000];
int notsetcol[500000];
int main()
{
    int n,q,i,count,ans=0,tx,tc,k,x,to,incol,inrow,allrows,allcols;
    char str[10];
    n=scan();
    q=scan();
    allrows=n;allcols=n;
    for(count=0;count<q;count++)
    {
        scanf("%s",str);
        i=scan();
        ans=n;
        if(strcmp(str,"RowQuery")==0)
        {
            memset(temp,1,sizeof(temp));
            if(row[i-1]==0)
            {
                ans=allrows;
                //printf("right place ");
                /*for(k=0;k<count;k++)
                {
                    if(allr[k]!=0)
                    {
                        to=allr[k]%10;
                        incol=allr[k]/10;
                        tx=(to==0)?1:-1;
                        if(temp[incol-1]!=tx)
                        {
                            ans+=tx;
                            temp[incol-1]=tx;
                        }
                    }
                }*/
            }
            else
            {
                tx=row[i-1]%10;
                tc=row[i-1]/10;
                if(tx==0) ans=n;
                else if(tx==1) ans=0;

                for(k=tc+1;k<count;k++)
                {
                    if(allr[k]!=0)
                    {
                        to=allr[k]%10;
                        incol=allr[k]/10;
                        tx=(to==0)?1:-1;
                        if(temp[incol-1]!=tx)
                        {
                            ans+=tx;
                            temp[incol-1]=tx;
                        }
                    }
                }
            }
            printf("%d\n",ans);
        }
        else if(strcmp(str,"RowSet")==0)
        {
            x=scan();
            allc[count]=i*10+x;
            row[i-1]=count*10+x;
            if(notsetrow[i-1]!=0)
            {
                if(x!=notsetrow[i-1]%10)
                {
                    tx=x==0?1:-1;
                    allcols+=tx;
                    notsetrow[i-1]=count*10+x;

                }
            }
            else
            {
                 tx=x==0?1:-1;
                 allcols+=tx;
                 notsetrow[i-1]=count*10+x;
            }
        }
        else if(strcmp(str,"ColSet")==0)
        {
            x=scan();

            allr[count]=i*10+x;
            col[i-1]=count*10+x;
            if(notsetcol[i-1]!=0)
            {
                if(x!=notsetcol[i-1]%10)
                {
                    tx=x==0?1:-1;
                    allrows+=tx;
                    notsetcol[i-1]=count*10+x;
                }
            }
            else
            {
                 tx=x==0?1:-1;
                 allrows+=tx;
                 notsetcol[i-1]=count*10+x;
            }
        }
        else if(strcmp(str,"ColQuery")==0)
        {
            memset(temp,1,sizeof(temp));
            if(col[i-1]==0)
            {
                ans=allcols;
                /*for(k=0;k<count;k++)
                {
                    if(allc[k]!=0)
                    {
                        to=allc[k]%10;
                        inrow=allc[k]/10;
                        tx=(to==0)?1:-1;
                        if(temp[inrow-1]!=tx)
                        {
                            ans+=tx;
                            temp[inrow-1]=tx;
                        }
                    }
                }*/
            }
            else
            {
                tx=col[i-1]%10;
                tc=col[i-1]/10;
                if(tx==0) ans=n;
                else if(tx==1) ans=0;

                for(k=tc+1;k<count;k++)
                {
                    if(allc[k]!=0)
                    {
                        to=allc[k]%10;
                        inrow=allc[k]/10;
                        tx=(to==0)?1:-1;
                        if(temp[inrow-1]!=tx)
                        {
                            ans+=tx;
                            temp[inrow-1]=tx;
                        }
                    }
                }
            }
            printf("%d\n",ans);

        }
    }
    return 0;
}
