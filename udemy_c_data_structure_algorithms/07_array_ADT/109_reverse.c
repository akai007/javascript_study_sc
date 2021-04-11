#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};


void printArray(struct Array arr)
{
  printf("Array:  \n");
  for (int i = 0; i < arr.length; i++)
  {
    printf("%d ", arr.A[i]);
  }
  printf(" \n");
  
};


void reverse(struct Array *arr)
{
    int t;
    for (int i = 0, j = arr->length-1; i < j; i++, j--)
    {
        t = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = t;
    }
}

int main(int argc, char const *argv[])
{
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};

    printArray(arr);
    reverse(&arr);
    printArray(arr);

    return 0;
}
