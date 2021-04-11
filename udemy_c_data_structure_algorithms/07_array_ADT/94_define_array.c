#include <stdio.h>
#include <stdlib.h>

struct Array
{
  int * A;
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

int main(int argc, char const *argv[])
{
  struct Array arr;
  int n, i;
  printf("Enter size of an array:  ");
  scanf("%d", &n);

  arr.A=(int *)malloc(arr.size * sizeof(int));

  printf("Enter number of Array: \n");
  for (i = 0; i < n; i++)
  {
    printf("[%d]: ", i);
    scanf("%d", &arr.A[i]);
  }
  arr.length = n;

  printArray(arr);

  return 0;
}
