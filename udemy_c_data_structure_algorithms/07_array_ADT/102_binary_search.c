#include <stdio.h>

struct Array
{
  int A[20];
  int size;
  int length;
};

int binarySearch(struct Array *arr, int num)
{
  int min, mid, max;
  min = 0;
  max = (arr->length)-1;

  while (min <= max)
  {
    mid = (min+max) / 2;
    if (num == arr->A[mid])
      return mid;

    if (num < arr->A[mid])
      max = mid-1;
    else 
      min = mid+1;
  }
  
  return -1;
}

int binarySearchRecursion(struct Array * arr, int min, int max, int num )
{
  if (min > max) return -1;
  
  int mid = (min + max) / 2;
  if (num == arr->A[mid]) return mid;

  if (num < arr->A[mid]) return binarySearchRecursion(arr, min, mid-1, num);
  else return binarySearchRecursion(arr, mid+1, max, num);

}


int main(int argc, char const *argv[])
{

  struct Array arr = {{3, 5, 9, 11, 16, 18, 20, 23, 24, 28, 33, 34, 38, 40 }, 20, 14};
  
  printf("%d \n", binarySearch(&arr, 5));
  printf("%d \n", binarySearch(&arr, 28));
  printf("%d \n", binarySearchRecursion(&arr, 0, arr.length, 28));

  return 0;
}
