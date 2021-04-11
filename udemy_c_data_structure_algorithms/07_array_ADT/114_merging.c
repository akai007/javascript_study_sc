#include <stdio.h>
#include <stdlib.h>

struct Array
{
  int A[20];
  int size;
  int length;
};

void printArray(struct Array *arr)
{
  for (int i = 0; i < arr->length; i++)
  {
    printf("%d ", arr->A[i]);
  }
  printf("\n");
}

struct Array * merge(struct Array * arrA, struct Array * arrB)
{
  int mergeLength = arrA->length + arrA->length;

  struct Array *arrMerge = (struct Array *)malloc((mergeLength+2) * sizeof(int));
  arrMerge->length = mergeLength;

  int i = 0;
  int j = 0;
  while ( i < arrA->length && j < arrB->length )
  {
    if (arrA->A[i] <= arrB->A[j])
    {
      arrMerge->A[i+j] = arrA->A[i];
      i++;
    }

    if (arrA->A[i] >= arrB->A[j])  
    {
      arrMerge->A[i+j] = arrB->A[j];
      j++;
    }
  }
  if (i < arrA->length-1)
  {
    while (i < arrA->length)
    {
      arrMerge->A[i+j] = arrA->A[i];
      i++;
    }
  }
  if (j < arrB->length-1)
  {
    while (j < arrA->length)
    {
      arrMerge->A[i+j] = arrB->A[j];
      j++;
    }
  }

  return arrMerge;
}


int main(int argc, char const *argv[])
{
  struct Array arr = {{1, 2, 3, 4, 5}, 20, 5};
  struct Array arr2 = {{2, 4, 6, 7, 8}, 20, 5};
  struct Array * mArr = merge(&arr, &arr2);
  printArray(mArr);
  
  return 0;
}
