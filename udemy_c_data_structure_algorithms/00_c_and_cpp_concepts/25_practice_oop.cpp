#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Rectangle
{
    private: 
        int length;
        int breadth;

    public:
        Rectangle(int l, int b) 
        {
            length = l;
            breadth = b;
        }
        int area()
        {
            return length * breadth;
        }

        int perimeter()
        {
            return 2 * ( length + breadth );
        }

        ~Rectangle()
        {
            cout<<"Destructor";
        }

    

};

int main()
{
    int length;
    int breadth;

    cout<<"Please Enter length"<<endl;
    scanf("%d", &length);
    cout<<"Enter breadth:"<<endl;
    scanf("%d", &breadth);


    Rectangle rec(length, breadth);

    printf("The area is: %d \n", rec.area());
    printf("The perimeter is: %d \n", rec.perimeter());

}