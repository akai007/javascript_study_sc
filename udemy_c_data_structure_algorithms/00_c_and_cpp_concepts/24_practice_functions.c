#include <stdio.h>

int area(int length, int breadth)
{
    return length * breadth;
}

int perimeter(int length, int breadth)
{
    return 2 * ( length + breadth );
}

int main()
{
    int length;
    int breadth;

    printf("Please Enter length");
    scanf("%d", &length);
    printf("Enter breadth:");
    scanf("%d", &breadth);

    printf("The area is: %d \n", area(length, breadth));
    printf("The perimeter is: %d \n", perimeter(length, breadth));

}