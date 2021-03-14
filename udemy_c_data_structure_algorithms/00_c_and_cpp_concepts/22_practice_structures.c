#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};

struct Rectangle * createRec(int length, int breadth) 
{
    struct Rectangle *rec = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    rec->length = length;
    rec->breadth = breadth;

    return rec;
}

int area(struct Rectangle *rec)
{
    return rec->length * rec->breadth;
}

int perimeter(struct Rectangle *rec)
{
    return 2 * ( (*rec).length + (*rec).breadth );
}

int main()
{
    struct Rectangle *rec;
    int length;
    int breadth;

    printf("Please Enter length");
    scanf("%d", &length);
    printf("Enter breadth:");
    scanf("%d", &breadth);

    rec = createRec(length, breadth);

    printf("The area is: %d \n", area(rec));
    printf("The perimeter is: %d \n", perimeter(rec));

    free(rec);
}