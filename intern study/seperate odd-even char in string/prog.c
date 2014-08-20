#include<stdio.h>
#include<string.h>

void swap(char *word,int i,int j)
{
    if(i>=j) return;

    int k;
    char temp;
    for(k=i+1;k<j;k+=2)
    {
        temp=word[k];
        word[k]=word[k+1];
        word[k+1]=temp;
    }
    swap(word,i+1,j-1);
}

int main()
{
    char str[]="a1b2c3d4e5f6g7h8i9";
    int l=strlen(str);
    int i;
    printf("%s\n",str);
    swap(str,0,l-1);
    printf("%s\n",str);

    return 0;
}
