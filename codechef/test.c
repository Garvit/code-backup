#include<stdio.h>
#include<math.h>
struct node
{
    char c;
};
struct node* t;
main()
{
    int a=-2,count=0;
    printf("%d\n",a>>1);
    unsigned int b=a;
    while(b)
    {
        printf("%d",b&1);
        b=b>>1;
        count++;
    }
    printf("\n%d",count);

}
