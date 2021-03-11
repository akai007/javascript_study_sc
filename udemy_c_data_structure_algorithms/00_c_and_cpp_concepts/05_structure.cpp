

#include <stdio.h>
#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
};


int main()
{
    struct Rectangle r1={10, 5}, r2, r3;
    r2.length = 20;
    r2.breadth = 4;

    printf("%lu\n", sizeof(r1));
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;
    cout<<r2.length<<endl;
    cout<<r2.breadth<<endl;

    return 0;
}