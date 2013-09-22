#include<stdio.h>
#include<string.h>
int com[49];
int graph[49][49];
int findmax()
{
    int max=com[0];
    int i;
    for(i=1;i<49;i++)
    {
        if(max<com[i])
            max=com[i];
    }
    return max;
}
int main()
{
    int t,n,s,e,c,i,j,l,z;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        memset(graph,0,sizeof(graph));
        //for(j=0;j<49;j++) printf("%d ",com[j]);
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d %d %d",&s,&e,&c);
            graph[s][e]=c;

        }
        for(j=1;j<49;j++)
        {
            int k;
            for(k=j;k>0;k--)
            {
                if(com[k]!=0)
                    break;
            }
            for(l=j+1;l<49;l++)
            {
                if(graph[j][l]!=0 && com[k]+graph[j][l]>com[l])
                {
                    //printf("j:%d k:%d l:%d",j,k,l);
                    com[l]=com[k]+graph[j][l];
                    //for(z=0;z<49;z++) printf("%d ",com[z]); printf("\n");
                }
            }
        }
        printf("%ld\n",findmax());
        //for(j=0;j<49;j++) printf("%d ",com[j]);
        memset(com,0,sizeof(com));
    }
    return 0;
}
