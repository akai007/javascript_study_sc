#include <stdio.h>

int main()
{
    int length;
    int breadth;

    printf("Please Enter length");
    scanf("%d", &length);
    printf("Enter breadth:");
    scanf("%d", &breadth);

    int area = length * breadth;
    int perimeter = 2 * ( length + breadth );

    printf("The area is: %d \n", area);
    printf("The perimeter is: %d \n", perimeter);

}