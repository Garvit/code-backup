#include<iostream>
#include<cstdio>

using namespace std;

bool visited[5][5];
size_t pathCount;
int length;
int longest=-1;
int shortest=-1;
bool exist(int arr[3][3], int i, int j, int m, int n)
{
    if (i<0 || j<0 || i>=m || j>=n) return false;
    if (arr[i][j] == 0 || visited[i][j]) return false;
    if (i==m-1 && j==n-1) return true;

    visited[i][j]=true;
    if (exist(arr,i+1,j,m,n) || exist(arr,i-1,j,m,n) || exist(arr,i,j+1,m,n) || exist(arr,i,j-1,m,n))
    {
        return true;
    }
    return false;
}
void count(int arr[3][3], int i, int j, int m, int n)
{
    if (i<0 || j<0 || i>=m || j>=n) return;
    if (arr[i][j]==0 || visited[i][j]) return;

    if (i==m-1 && j==n-1)
    {
        ++pathCount;
        if (longest == -1 || length > longest)
        {
            longest = length;
        }
        if (shortest == -1 || length < shortest)
        {
            shortest = length;
        }
        return;
    }
    visited[i][j] = true;
    ++length;
    count(arr,i+1,j,m,n);
    count(arr,i-1,j,m,n);
    count(arr,i,j+1,m,n);
    count(arr,i,j-1,m,n);
    --length;
    visited[i][j] = false;
}
int main()
{
    int arr[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    count(arr,0,0,3,3);
    cout << pathCount << endl;
    cout << shortest << endl;
    cout << longest << endl;
    return 0;
}
