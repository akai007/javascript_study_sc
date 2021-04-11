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

void insert(struct Array * arr, int val)
{
    int i = arr->length-1;
    while (arr->A[i] > val)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    
    arr->A[i+1] = val;
    arr->length++;
}

int isSorted(struct Array * arr)
{
    for (int i = 1; i < arr->length; i++)
    {
        if (arr->A[i-1] > arr->A[i])
        {
            return 0;
        }
        
    }
    return 1;
}


int main(int argc, char const *argv[])
{
    
    struct Array arr = {{2, 3, 4, 5, 6}, 20, 5};
    struct Array arrNotSorted = {{2, 3, 4, 99, 6}, 20, 5};

    printArray(arr);
    insert(&arr, 4);
    printArray(arr);

    printf("%d \n", isSorted(&arr));
    printf("%d \n", isSorted(&arrNotSorted));

    return 0;
}
