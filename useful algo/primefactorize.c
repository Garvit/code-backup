void primefactors(int n)
{
    int num;
    num=n;
    if(num%2==0){
        while(num%2==0)
        {
            num/=2;
            printf("2 ");
        }
        }
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(num==1) break;

        if(num%i==0){
        while(num%i==0)
        {
            num/=i;
            printf("%d ",c);
        }
        }

    }
}
