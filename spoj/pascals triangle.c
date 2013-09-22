int arr[1001][1001];
void pascals()
{
    int i,j;
    arr[0][0]=1;
    for(i=1;i<=1000;i++)
    {
        arr[i][0]=1;
        for(j=1;j<=i;j++)
        {
            arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%MOD;
        }
    }
}
