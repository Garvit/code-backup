#include<iostream>

using namespace std;

int main()
{
    /*auto x=5;
    decltype(x) y=3.2;
    cout<<y;*/
    enum class Color
    {
        RED,
        BLUE
    };

    enum class Fruit
    {
        BANANA,
        APPLE
    };
    cout<<__cplusplus;
    //static_assert(__cplusplus > 199711L, "Program requires C++11 capable compiler");
    return 0;
}
