#include<stdio.h>
int inline scan(FILE *fp)
{
    int N = 0;
    char C;
    C=fgetc(fp);
    while (C < '0' || C>'9') C=fgetc(fp);
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=fgetc(fp);
    }

    return N;
}
int main()
{
    int m;
    char s[550];
    FILE *fp1,*fp2;
    fp1=fopen("input.txt","r");
    //fp2=fopen("output.txt","w");
    fscanf(fp1,"%d",&m);
    printf("%d",m);
    /*while(m--)
    {
        //s=fgets(s,500,fp1);
        //printf("%s\n",s);
    }*/
    fclose(fp1);
    return 0;
}
