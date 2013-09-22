#include<stdio.h>

void swap(int **a,int i,int j);
int partition(int **a,int start,int end,int i);
void find(int **a,int start,int end,int l);
int *p,n,*b;

main()
{
    //int a[3][2]={{1,1},{3,2},{2,3}};
    scanf("%d",&n);
    int **a=calloc(n,sizeof(int*));
    int i=0;
    printf("Enter the sizes of nuts\n");
    for(i=0;i<3;i++)
    {
        a[i]=calloc(2,sizeof(int));
        scanf("%d",&a[i][0]);
        a[i][1]=i+1;
    }
    printf("Enter the sizes of bolts\n");
    b=calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }


    p=calloc(n,sizeof(int));

    /*for(i=0;i<n;i++)
    {
        p[i]=calloc(n,sizeof(int));
    }*/
    for(i=0;i<n;i++)
    {
       find(a,0,n-1,i);

    }
    //partition(a,0,2,1);
    //swap(a,1,2);

}
void find(int **a,int start,int end,int l)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(p[i]==0)
            break;

        if(p[i]-1>=start && p[i]-1<=end)
        {
            if(b[l]<a[p[i]-1][0])
            {
                end=p[i]-2;
            }
            else
                start=p[i];
        }

    }

    int j;
    for(j=start;j<=end;j++)
    {

        if(a[j][0]==b[l])
        {

            printf("Pair: Nut %d Bolt %d \n",a[j][1],l+1);
            //p[i]=j+1;
            p[i]=partition(a,start,end,j)+1;

        }
    }

}
int partition(int **a,int start,int end,int i)
{
    swap(a,i,end);
    int part=a[end][0];
    int k=start-1;
    int j=start;
    for(j=start;j<end;j++)
    {
        if(a[j][0]<=part)
        {
            k++;
            swap(a,k,j);
        }
    }
    k++;
    swap(a,k,end);
    return k;

}
void swap(int **a,int i,int j)
{
    int *temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
