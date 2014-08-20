#include<iostream>

using namespace std;

void func(int &x,int &y)
{
    x=4;y=5;
}
void func1(int* x,int* y)
{
    *x=*x+*y;
}
int main()
{
    int x=5,y=4;
    cout<<x<<" "<<y<<endl;
    func(x,y);
    cout<<x<<" "<<y<<endl;
    func1(&x,&y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
